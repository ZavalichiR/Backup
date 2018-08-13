 package L4;

import java.net.URL;
import java.io.InputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.net.URLConnection;
import java.nio.charset.Charset;
import java.text.ParseException;
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.text.SimpleDateFormat;
import org.xml.sax.Attributes;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;
import org.xml.sax.XMLReader;
import org.xml.sax.helpers.DefaultHandler;
import org.xml.sax.helpers.XMLReaderFactory;

public class RSSReader {
    static public class MyHandler extends DefaultHandler {
        private final static Logger LOGGER = Logger.getLogger(MyHandler.class.getName());

        private SortedSet<Item> itemList = new TreeSet<Item>();
        boolean t = false;
        boolean d = false;
        boolean dn = false;
        boolean l = false;
        Item It;

        public MyHandler() {
        }
        // apelată la începutul parsării
        public void startDocument() {
            LOGGER.log(Level.INFO, "Start document");
        }
        // apelată la terminarea parsării
        public void endDocument() {
            LOGGER.log(Level.INFO, "End document");
        }
        // apelată la întâlnirea unui tag de start
        public void startElement(String uri, String name, String qName, Attributes atts)
        {
            LOGGER.log(Level.INFO, "Start element: " + name);
            if (name != null) {
                switch (name) {
                    case "item":
                        It = new Item();
                        break;
                    case "title":
                        t = true;
                        break;
                    case "pubDate":
                        d = true;
                        break;
                    case "description":
                        dn = true;
                        break;
                    case "link":
                        l = true;
                        break;
                }
            }
        }
        // apelată la întâlnirea unui tag de sfârșit
        public void endElement(String uri, String name, String qName) {
            LOGGER.log(Level.INFO, "End element: " + name);
            switch (name)
            {
                case "title":
                    t = false;
                    break;
                case "pubDate":
                    d = false;
                    break;
                case "description":
                    dn = false;
                    break;
                case "link":
                    l = false;
                    break;
                case "item":
                    itemList.add(It);
                    break;
            }

        }
        // apelată la întâlnirea unui text în interiorul unui element
        public void characters(char ch[], int start, int length) {
            String msg = new String(ch, start, length);
            msg = msg.trim();
            if (!msg.equals("")) {
                LOGGER.log(Level.INFO, "Text: \"" + msg.trim() + "\"");
            }

            if (It != null) {
                if (t) {
                    It.setTitle(msg);
                }
                if (d) {
                    try {
                        SimpleDateFormat formatter = new SimpleDateFormat("EEE, dd MMM yyyy HH:mm:ss zzz");
                        Date date = formatter.parse(msg);
                        It.setPubDate(date);
                    } catch (ParseException e) {
                        e.printStackTrace();
                        It.setPubDate(new Date());
                    }
                }
                if (dn) {
                    It.setDescription(msg);
                }
                if (l) {
                    It.setLink(msg);
                }
            }
        }

        // afiseaza lista cu rezultatul parsarii
        public void afisare() {
            Iterator i = itemList.iterator();
            while (i.hasNext())
            {
                System.out.println(i.next().toString());
            }
        }
    }

    public static void main(String[] args) throws SAXException, IOException {
        // crearea unei instanțe a parserului/readerului
        XMLReader xmlReader = XMLReaderFactory.createXMLReader();
        // crearea unei instanțe a clasei care va face interpretarea propriu‐zisă a XMLului
        RSSReader.MyHandler handler = new RSSReader.MyHandler();
        // înregistrarea handler‐ului la reader
        xmlReader.setContentHandler(handler);
        xmlReader.setErrorHandler(handler);

        // deschiderea URL-urilor din fisier pentru citirea RSS Feed-urilor
        InputStream fisier = new FileInputStream("sites.txt");
        InputStreamReader fis = new InputStreamReader(fisier, Charset.forName("UTF-8"));
        BufferedReader buff = new BufferedReader(fis);

        // citim din fisier fiecare URL in parte
        String website;
        while ((website = buff.readLine()) != null) {
            URL url = new URL(website);
            URLConnection uC = url.openConnection();
            // parsarea propriu‐zisă
            xmlReader.parse(new InputSource(uC.getInputStream()));
        }

        // afisarea rezultatului parsarii
        System.out.println("\nObiectele rezultate dupa parsare:\n");
        handler.afisare();
    }
}
