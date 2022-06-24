using System;
using System.IO;
using System.Text.Json;

namespace FinalTestSample
{
    public class FileLogger
    {
        public string _fileName { get; set; }

        public FileLogger(string fileName)
        {
            //문제 6: 파일 만들기
            //_fileName에 filename + 날짜.log 로 로그파일명 저장
            //예제 > fileName이 Log일때 Log220616.log
            _fileName = fileName + DateTime.Today.ToString("yyMMdd")+".log";
        }

        public void Write(string logType, string logMessage)
        {
            //문제 7:

            /*StreamWriter Log_Write;
            DateTime Today_Date = DateTime.Today;
            string day = Today_Date.ToString("yyMMdd");
            string input_time = Today_Date.ToString("yyyy-MM-dd HH:mm:ss");
            string Log_path = $@"Log{day}.txt";
            if (File.Exists(Log_path))
            {
                string input_Log = $"[{input_time}]<{logType}>로그인 에러 {logMessage}";
                Log_Write = File.AppendText(Log_path);
                Log_Write.WriteLine(input_Log);
                Log_Write.Close();
            }*/

            string currentDirectoryPath = Environment.CurrentDirectory.ToString();    
            string DirPath = System.IO.Path.Combine(currentDirectoryPath, "Logs");    
            string FilePath = DirPath + @"\Log_" + DateTime.Today.ToString("yyyyMMdd") + ".log";    
            DirectoryInfo di = new DirectoryInfo(DirPath);    
            FileInfo fi = new FileInfo(FilePath);  
            

            try{        
                
                if (!di.Exists) Directory.CreateDirectory(DirPath);        
                string error_string = string.Format(DateTime.Today.ToString("yyyyMMdd"));        

                if (!fi.Exists){            
                        using (StreamWriter sw = new StreamWriter(FilePath)){                
                        sw.WriteLine(error_string);                
                        sw.Close();  
                        
                        }   
                        
                }
                else{            
                    using (StreamWriter sw = File.AppendText(FilePath)){                
                        sw.WriteLine(error_string);                
                        sw.Close();            
                    }        
                }  
                
            }   
            

            catch { 
                
            }

        }

        

    }
}
