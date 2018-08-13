package l4;

import java.util.List;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

import org.xml.sax.Attributes;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;
import org.xml.sax.XMLReader;
import org.xml.sax.helpers.DefaultHandler;
import org.xml.sax.helpers.XMLReaderFactory;

public class RSSReader {

    static public class MyHandler extends DefaultHandler {

    	
    	private List<Item> myList=new ArrayList<Item>();
    	private Item it;
    	private String msg;
    	private String lastTag;
        private final static Logger LOGGER = Logger.getLogger(MyHandler.class.getName());

        public MyHandler() {
        }

        // apelată la începutul parsării
        public void startDocument() {
            LOGGER.log(Level.INFO, "Start document");
        }

        // apelată la terminarea parsării
        public void endDocument() {
            LOGGER.log(Level.INFO, "End document");
            for(Item el:myList)
            {
            	System.out.println(el);
            }
        }

        // apelată la întâlnirea unui tag de start
        public void startElement(String uri, String name, String qName, Attributes atts) {
            LOGGER.log(Level.INFO, "Start element: " + name);
            
            if(name.equals("item"))
            {
            	lastTag="item";
            	it = new Item();
				myList.add(it);
            }
        }

        // apelată la întâlnirea unui tag de sfârșit
        public void endElement(String uri, String name, String qName) {
            LOGGER.log(Level.INFO, "End element: " + name);
            if(it!=null)
            {
            	switch(name)
                {

                case "title":
                	it.setTitle(msg);
                	break;
                case "link":
                	it.setLink(msg);
                	break;
                case "description":
                	it.setDescription(msg);
                	break;
                }
            }
            
        }
        
        // apelată la întâlnirea unui text în interiorul unui element
        public void characters(char ch[], int start, int length) {
            String message = new String(ch, start, length);
            message = message.trim();
            if (!message.equals("")) {
                LOGGER.log(Level.INFO, "Text:    \"" + message.trim() + "\"");
                msg=message;
            }
        }
    }

    public static void main(String[] args) throws SAXException, IOException {
        // crearea unei instanțe a parserului/readerului
        XMLReader xmlReader = XMLReaderFactory.createXMLReader();
        // crearea unei instanțe a clasei care va face interpretarea propriu-zisă a XML-ului
        RSSReader.MyHandler handler = new RSSReader.MyHandler();
        // înregistrarea handler-ului la reader 
        xmlReader.setContentHandler(handler);
        xmlReader.setErrorHandler(handler);
        // deschiderea fișierului XML pentru citire
        FileReader fileReader = new FileReader("rssfeed.xml");
        // parsarea propriu-zisă
        xmlReader.parse(new InputSource(fileReader));
        //
    }
}