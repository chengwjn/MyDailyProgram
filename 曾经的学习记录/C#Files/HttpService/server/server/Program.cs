using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.IO;
using System.Threading;


namespace server
{
    class Program
    {
        static HttpListener httpobj;
        static void Main(string[] args)
        {
            string Address = "http://127.0.0.1:8080/";
            httpobj = new HttpListener();
            httpobj.Prefixes.Add(Address);//定义url及端口号，通常设置为配置文件
            httpobj.Start();//启动监听器
            httpobj.BeginGetContext(Result, null);//异步监听客户端的请求，当客户端的网络请求到时会自动执行Result委托
            Console.WriteLine("服务器初始化完毕，正在等待客户端请求，时间{0}",DateTime.Now.ToString());
            Console.ReadKey();
        }
        private static void Result(IAsyncResult ar)
        {
            //当接收到请求后程序流会走到这里
            httpobj.BeginGetContext(Result,null);
            var guid=Guid.NewGuid().ToString();
            string returnObj = null;
            var context = httpobj.EndGetContext(ar);
            var request = context.Request;
            var response = context.Response;
            context.Response.ContentType = "text/plain;charset=UTF-8";
            context.Response.ContentEncoding = Encoding.UTF8;
            if (request.HttpMethod == "POST" && request.InputStream != null)
            {
                //处理客户端发送的请求并返回处理信息
                returnObj = HandleRequest(request, response);
            }
            else
                {
                returnObj = "不是post请求或者传过来的数据为空";
            }
            var returnByteArr = Encoding.UTF8.GetBytes(returnObj);
            try
            {
                using (var stream = response.OutputStream)
                {
                    //把处理信息返回到客户端
                    stream.Write(returnByteArr, 0, returnByteArr.Length);
                }
            }
            catch (Exception ex)
            {
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine("网络崩溃：{0}",ex.ToString());
            }
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("请求处理完成：{0},时间：{1}\r\n",guid,DateTime.Now.ToString());}
             private static string HandleRequest(HttpListenerRequest request, HttpListenerResponse response)
        {
            string data = null;
            try
            {
                var byteList = new List<byte>();
                var byteArr = new byte[2048];
                int readLen = 0;
                int len = 0;
                //接收客户端传过来的数据并转成字符串类型
                do
                {
                    readLen = request.InputStream.Read(byteArr, 0, byteArr.Length);
                    len += readLen;
                    byteList.AddRange(byteArr);
                } while (readLen != 0);
                data = Encoding.UTF8.GetString(byteList.ToArray(),0, len);

                //获取得到数据data可以进行其他操作
            }
            catch (Exception ex)
            {
                response.StatusDescription = "404";
                response.StatusCode = 404;
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine("在接收数据时发生错误:{0}",ex.ToString());
                return "在接收数据时发生错误";//把服务端错误信息直接返回可能会导致信息不安全，此处仅供参考
            }
            response.StatusDescription = "200";//获取或设置返回给客户端的 HTTP 状态代码的文本说明。
            response.StatusCode = 200;// 获取或设置返回给客户端的 HTTP 状态代码。
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("接收数据完成:{0},时间：{1}", data.Trim(),DateTime.Now.ToString());
            return "接收数据完成";
        }
    }
        }
        
    

