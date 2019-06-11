using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string time = DateTime.Now.ToString("yyyyMMdd-HH.mm.ss");//获取当前时间
            //Console.WriteLine(time);
            string path = "C:/Users/**********/Desktop/" + time;
            string name = time + ".txt";
            string location = path + "/" + name;
            Directory.CreateDirectory(path);//按照路径生成文件夹
            Console.ReadKey();
        }
    }
}
