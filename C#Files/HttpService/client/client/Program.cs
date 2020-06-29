using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.IO;
using System.Threading;
using Newtonsoft.Json;


namespace client
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入服务器ip地址：");
            string address = Console.ReadLine();
            while(true)
            {
                var wc = new WebClient();
                var url = "http://"+address+":8080";
                Console.WriteLine("请求服务地址:{0}，时间：{1}",url,DateTime.Now.ToString());
                //模拟一个json数据发送到服务端
                Console.WriteLine("输入要发送的信息：");
                string a = Console.ReadLine();
                var data = new Data(a);
                var jsonModel = JsonConvert.SerializeObject(data);
                //发送到服务端并获得返回值
                var returnInfo = wc.UploadData(url, Encoding.UTF8.GetBytes(jsonModel));
                //把服务端返回的信息转成字符串
                var str = Encoding.UTF8.GetString(returnInfo);
                Console.ForegroundColor = ConsoleColor.Cyan;
                Console.WriteLine("服务端返回信息：{0},时间：{1}",str,DateTime.Now.ToString());
                Console.ForegroundColor = ConsoleColor.White;
            } 
        }
        class Data
        {
            public Data(string message)
            {              
                this.Message = message;
            }
            public string Message { get; set; }
        }
    }
}
