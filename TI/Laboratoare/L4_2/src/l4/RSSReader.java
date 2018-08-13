package l4;

import java.net.*;

import java.util.List;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;
import java.text.ParseException;
import java.text.SimpleDateFormat;
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
    	//private String lastTag;
    	private SimpleDateFormat formatter = new SimpleDateFormat("EEE, dd MMM yyyy HH:mm:ss zzz");
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
            	//lastTag="item";	
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
                case "pubDate":          	
                	try {
                		System.out.println("A intrat in pub date");
    					it.setPubDate(formatter.parse(msg));
    				} catch (ParseException e) {
    					// TODO Auto-generated catch block
    					e.printStackTrace();
    				}
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
		// crearea unei instanțe a clasei care va face interpretarea
		// propriu-zisă a XML-ului
		RSSReader.MyHandler handler = new RSSReader.MyHandler();
		// înregistrarea handler-ului la reader
		xmlReader.setContentHandler(handler);
		xmlReader.setErrorHandler(handler);
		// deschiderea fișierului XML pentru citire
		URL xmlUrl = new URL("http://www.dc.ac.tuiasi.ro/feed/");
        URLConnection yc = xmlUrl.openConnection();
        BufferedReader in = new BufferedReader(new InputStreamReader(yc.getInputStream()));
		// parsarea propriu-zisă
		xmlReader.parse(new InputSource(in));
		//
	}
}