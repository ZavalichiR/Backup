using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Web;
using System.Web.Services;
using System.Xml.Serialization;
namespace webservice_chat
{
    public class ChatManagerWS : WebService
    {
        [WebMethod(EnableSession = true)]
        public bool CheckUserAuthentication(out string response)
        {
            if (Session["user_name"] == null)
            {
                response = "Not connected";
                return false;
            }
            string user_name = (string)Session["user_name"];
            if (Application["connected_users"] == null)
            {
                response = "Server error";
                return false;
            }
            List<string> connected_users = (List<string>)Application["connected_users"];
            if (connected_users.IndexOf(user_name) >= 0)
            {
                response = "User is connected";
                return true;
            }
            else
            {
                response = "User has not been properly authenticated";
                return false;
            }
        }
        [WebMethod(EnableSession = true)]
        public bool Connect(String user_name, out String message)
        {
            Regex reg = new Regex("^[a-zA-Z0-9]{4,}$");
            if (!reg.IsMatch(user_name))
            {
                message = "Incorrect username format";
                return false;
            }
            if (Session["user_name"] != null)
            {
                message = "Already connected with a user name";
                return false;
            }
            List<string> connected_users;
            if (Application["connected_users"] != null)
                connected_users = (List<string>)Application["connected_users"];
            else
                Application["connected_users"] = connected_users = new List<string>();
            if (connected_users.IndexOf(user_name) >= 0)
            {
                message = "User name is taken";
                return false;
            }
            else
            {
                connected_users.Add(user_name);
                Session["user_name"] = user_name;
                message = "Successful connection";
                return true;
            }
        }
        [WebMethod(EnableSession = true)]
        public bool Disconnect(out string response)
        {
            if (CheckUserAuthentication(out response))
            {
                response = "User has been disconnected";
                string asd = (string)Session["user_name"];
                Session["user_name"] = null;
                return true;
            }
            else
            {
                Session["user_name"] = null;
                return false;
            }
        }
        [WebMethod(EnableSession = true)]
        public bool SendMessage(string message, out string response)
        {
            if (!CheckUserAuthentication(out response))
                return false;

            //exista deoarece userul este autentificat
            List<string> connected_users = (List<string>)Application["connected_users"];

            List<Message> stored_messages;
            if (Application["stored_messages"] != null)
                stored_messages = (List<Message>)Application["stored_messages"];
            else
                Application["stored_messages"] = stored_messages = new List<Message>();

            string user_name = (string)Session["user_name"];
            Message msg = new Message();
            msg.sender = user_name;
            msg.receiver = null;
            msg.text = message;
            msg.date = DateTime.Now;

            response = null;

            if (message[0] == '/')
            {
                int first_space = message.IndexOf(' ');
                string command = message.Substring(0, first_space);
                message = message.Remove(0, first_space + 1);
                switch(command)
                {
                    case "/w":
                        int second_space = message.IndexOf(' ');
                        string receiver = message.Substring(0, message.IndexOf(' '));
                        message = message.Remove(0, second_space + 1);
                        //verificare receiver
                        if (connected_users.IndexOf(receiver) < 0)
                        {
                            response = "Unknown user!";
                            return false;
                        }
                        msg.receiver = receiver;
                        msg.text = message;
                        break;
                    default:
                        response = "Unknown command!";
                        return false;
                }
            }
            stored_messages.Add(msg);
            return true;
        }
        [WebMethod(EnableSession = true)]
        public bool GetMessages(out string response, out List<Message> messages)
        {
            messages = new List<Message>();
            response = null;
            //verifc daca autentificarea e corecta doar daca este setat un user_name
            if (Session["user_name"] != null && !CheckUserAuthentication(out response))
                return false;
            string user_name = (string)Session["user_name"];
            DateTime last_update = DateTime.MinValue;
            if (Session["last_update"] != null)
                 last_update= (DateTime)Session["last_update"];
            if (Application["stored_messages"] == null)
            {
                return true;
            }
            List<Message> stored_messages = (List<Message>)Application["stored_messages"];
            foreach(Message msg in stored_messages)
            {
                if (msg.date > last_update
                    && (msg.receiver == null || (user_name != null && msg.receiver == user_name)))
                {
                    messages.Add(msg);
                }
            }
            Session["last_update"] = DateTime.Now;
            return true;
        }
    }
    public class Message
    {
        public string text;
        public string sender;
        public string receiver;
        public DateTime date;
    }
}