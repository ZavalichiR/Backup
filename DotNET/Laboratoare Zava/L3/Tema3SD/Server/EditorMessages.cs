using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Server
{
    public enum MSG_TYPE
    {
        UNDEFINED,
        NEW_CLIENT,
        CLIENT_DISCONNECTED,
        NEW_TEXT
    }

    [Serializable]
    public class EditorMessages
    {
        private MSG_TYPE type;
        private string text;
        private string msgSource;
        public EditorMessages(MSG_TYPE type)
        {
            this.type = type;
            text = null;
            msgSource = null;
        }
        public EditorMessages(MSG_TYPE type, string source)
        {
            this.type = type;
            this.msgSource = source;
        }
        public EditorMessages(MSG_TYPE type, string source,string text)
        {
            this.type = type;
            this.msgSource = source;
            this.text = text;
        }
        public EditorMessages()
        {
            this.type = MSG_TYPE.UNDEFINED;
        }
        public string Text
        {
            get { return text; }
            set { text = value; }
        }
        public MSG_TYPE Type
        {
            get { return type; }
            set { type = value; }
        }
        public string  MessageSource
        {
            get { return msgSource; }
            set { msgSource = value; }
        }

    }
}
