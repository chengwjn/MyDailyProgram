using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net.Sockets;
using System.Net;
using System.Threading;

namespace Server
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void BtnListen_Click(object sender, EventArgs e)
        {
            try
            {
                //点击开始监听
                Socket sockeWatch = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                IPAddress ip = IPAddress.Any;
                IPEndPoint point = new IPEndPoint(ip, Convert.ToInt32(txtPort.Text));

                sockeWatch.Bind(point);//绑定串口号
                lsbMessage.Items.Add("监听成功");
                sockeWatch.Listen(10);//设置监听

                //创建监听线程
                Thread thread = new Thread(Listen);
                thread.IsBackground = true;
                thread.Start(sockeWatch);
            }
            catch { }
        }
        Socket socketSend;
        void Listen(object o)
        {
            try
            {
                Socket socketWatch = o as Socket;
                while (true)
                {
                    socketSend = socketWatch.Accept();//等待接受客户端连接
                    lsbMessage.Items.Add("Client" + ":" + "连接成功!");//socketSend.RemoteEndPoint.ToString()

                    //开启新线程，执行接受消息的方法
                    Thread r_thread = new Thread(Received);
                    r_thread.IsBackground = true;
                    r_thread.Start(socketSend);
                }
            }
            catch { }
        }
        void Received(object o)
        {
            try
            {
                Socket socketSend = o as Socket;
                while (true)
                {
                    //客户端连接服务器成功后，服务器接收客户端发送的消息
                    byte[] buffer = new byte[1024 * 1024 * 3];
                    //实际接收到的有效字节数
                    int len = socketSend.Receive(buffer);
                    if (len == 0)
                    {
                        break;
                    }
                    string str = Encoding.UTF8.GetString(buffer, 0, len);//(socketSend.RemoteEndPoint + ":" + str+"\n");
                    lsbMessage.Items.Add("Client"+ ":" + str);//socketSend.RemoteEndPoint
                }
            }
            catch { }
        }
        void Send(string str)
        {
            byte[] buffer = Encoding.UTF8.GetBytes(str);
            socketSend.Send(buffer);
         }

        private void BtnSend_Click(object sender, EventArgs e)
        {
            Send(txtSend.Text.Trim());
            lsbMessage.Items.Add("Local:"+txtSend.Text + "\n");
            txtSend.Clear(); 
        }
    }
}
