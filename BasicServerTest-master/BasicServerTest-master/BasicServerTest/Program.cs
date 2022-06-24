using System.Net;
using System.Threading;
using System.Text.Json;


namespace FinalTestSample
{
    class data
    {

    }

    public class Global
    {
        public static Mutex mut = new Mutex();    
        
        public static List<string> id = new List<string>();

        public static void InitServer()
        {
            //서버 초기화 로직을 여기에 담으세요
            //그게 뭔데

        }

        public static void ContextHandle(object httplistener)
        {
            mut.WaitOne();
            HttpListener listener = (HttpListener)httplistener;
            HttpListenerContext context = listener.GetContext();
            mut.ReleaseMutex();

            //문제 1 : 사용자의 입력을 받고 출력을 한다.
            //
            //
            //
            //---------------------------
            //여기부턴 예제입니다.

            HttpListenerRequest request = context.Request;
            HttpListenerResponse response = context.Response;
            response.AddHeader("Access-Control-Allow-Origin", "*");
            Stream body = request.InputStream;
            System.Text.Encoding encoding = request.ContentEncoding;
            System.IO.StreamReader reader = new System.IO.StreamReader(body, encoding);

            string rawurl = request.RawUrl;
            string httpmethod = request.HttpMethod;

            string result = "";

            result += string.Format("httpmethod = {0}\r\n", httpmethod);
            result += string.Format("rawurl = {0}\r\n", rawurl);
            System.Console.WriteLine(result);


            Message a = new Message();
            string responseString = JsonSerializer.Serialize(a);
            System.Console.WriteLine(responseString);
            byte[] buffer = System.Text.Encoding.UTF8.GetBytes(responseString);
            response.OutputStream.Write(buffer, 0, buffer.Length);
            response.OutputStream.Close();

            //----------------------------요기까지
        }

        public static int GetServerID()
        {
            //서버에서 고유 id를 부여해서 리턴하시오
            return 0;
            
        }


 
    }

    public class ServerLoop
    {
        public static Mutex mut = new Mutex();
        HttpListener _listener;
        string _address;

        public ServerLoop(string address, string port)
        {
            RestartLoop();
            //문제2 :_address에 localhost 주소와 port가 입력된 주소를 작성하시오

            _address = address +":"+port;

        }

        public void RestartLoop()
        {
            _listener = new HttpListener();
        }

        

        public void AddRestAPI(string apiName)
        {
            //문제3 :address 뒤에 apiName이 추가된 prefix를 추가하세요
            _listener.Prefixes.Add(_address + "/" + apiName+"/");

        }
        public void Run()
        {
            _listener.Start();
            Console.WriteLine("Listening...");


            while (true)
            {
                ///문제4: 응답이 들어올경우 mutex를 이용하여 아래 코드를 새로운 접속이 생길때마다 1개의 Thread가 생기도록 개선하시오
                mut.WaitOne();
                Thread t = new Thread(new ParameterizedThreadStart(Global.ContextHandle));
                 t.Start(_listener);
                mut.ReleaseMutex();
            }
        }

        public void Close()
        {
            _listener.Stop();
        }

       

        void EndLoop()
        {
            if (_listener != null)
            {
                _listener.Stop();
                _listener.Close();
            }
        }
    }



    public class Program
    {
        public static int Main()
        {
            FileLogger fLog = new FileLogger("Log");

            Global.InitServer();

            //Log type 종류
            //<Exception>
            //<Debug>
            //<Record>
            fLog.Write("Debug","I hate life.");
            fLog.Write("Recoord", "dis");

            ServerLoop server = new ServerLoop("http://127.0.0.1","3000");
            server.AddRestAPI("LOGIN");
                  /*Req
                    {

                         id: sanahus,

                         pass: ********,

                         nick: 윈터,

                    }

                  Res

                   {

                             tocken_id: 1929391,

                    }*/
            server.AddRestAPI("LOGOUT");
            /*Req

            {

            tocken_id: 203020

            }

            Res
            {

            success: true,

            }*/
            server.AddRestAPI("STATUS_UPDATE");
           /* Req

            {

            tocken_id: 203020

            }

            Res
            {

            success: true,

            id: sanahus,

            nick: 윈터,

            }*/


            server.Run();
            server.Close();


            return 0;
        }
    }
}