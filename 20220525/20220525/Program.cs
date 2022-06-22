using System;
using System.Collections.Generic;
using System.Threading;
using System.Diagnostics;

namespace Cloth_Timer
{
    class Program
    {
        static Stopwatch stopWatch = new Stopwatch();//스톱워치 객체 생성
        static Random r = new Random();//랜덤 타입의 객체 생성

        static void Main(string[] args) // 5초
        {

            while (true)//무한루프
            {
                stopWatch.Start();//스탑워치 시작
                bool isRuning = true;

                // 코루틴 메소드 호출
                IEnumerable<int> c = Foo();
                IEnumerator<int> e = c.GetEnumerator();
                int y = 0;

                e.MoveNext();
                int ret1 = e.Current;

                while (isRuning)
                {
                    if (stopWatch.Elapsed.Seconds >= 5)
                    {
                        y = r.Next(1, 6);
                        Console.WriteLine("[민주]" + y + "번 옷 입었어!!!");
                        isRuning = false;
                    }
                }

                if (ret1 == y)
                {
                    Console.WriteLine("[태수]이제 출발하자~!\n");
                    stopWatch.Stop();
                    break;
                }
                else
                {
                    Console.WriteLine("[태수]다시 입어!\n");
                    stopWatch.Restart();
                }
            }
        }

        // COROUTINE - 컬렉션 인터페이스 타입으로 반환하는 경우
        public static IEnumerable<int> Foo() // 3초 
        {
            bool isRuning = true;
            int x = 0;

            while (isRuning)
            {
                if (stopWatch.Elapsed.Seconds >= 3)
                {
                    x = r.Next(1, 6);
                    Console.WriteLine("[태수]" + x + "번 옷 입었당!");
                    isRuning = false;
                }
            }
            yield return x;
        }
    }
}