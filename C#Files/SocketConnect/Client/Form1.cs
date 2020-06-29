using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;
using System.Threading;

namespace Client
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Control.CheckForIllegalCrossThreadCalls = false;
        }
        Socket socketsend;

        private void BtnConnect_Click(object sender, EventArgs e)
        {
            try
            {
                socketsend = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                IPAddress ip = IPAddress.Parse(txtIP.Text);
                IPEndPoint point = new IPEndPoint(ip, Convert.ToInt32(txtPort.Text));

                socketsend.Connect(point);//("连接成功!"+"\n");
                lsbMessage.Items.Add("连接成功!");
                //开启新线程，不停地接受服务器发来的信息
                Thread c_thread = new Thread(Received);
                c_thread.IsBackground = true;
                c_thread.Start();
            }
            catch(Exception)
            {
                lsbMessage.Items.Add("IP或端口号错误");
            }
        }
        void Received()
        {
            while (true)
            {
                try
                {
                    byte[] buffer = new byte[1024 * 1024 * 3];//实际接收到的有效字数
                    int len = socketsend.Receive(buffer);
                    if (len == 0)
                    {
                        break;
                    }
                    string str = Encoding.UTF8.GetString(buffer, 0, len);
                    lsbMessage.Items.Add("Server" + ":" + str);//socketsend.RemoteEndPoint
                }
                catch { }
            }
            
        }
        
        private void BtnSend_Click(object sender, EventArgs e)
        {
            try
            {
                string msg = txtSend.Text.Trim();
                txtSend.Clear();
                lsbMessage.Items.Add("Local:"+msg + "\n");
                byte[] buffer = new byte[1024 * 1024 * 3];
                buffer = Encoding.UTF8.GetBytes(msg);
                socketsend.Send(buffer);
            }
            catch { }
        }
    }
}
