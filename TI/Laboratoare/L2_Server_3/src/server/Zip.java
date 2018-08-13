package server;
import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.zip.GZIPOutputStream;
import java.util.zip.*;

public class Zip {
	
	public static byte[] compress(final String str) throws IOException {
	    if ((str == null) || (str.length() == 0)) {
	      return null;
	    }
	    ByteArrayOutputStream obj = new ByteArrayOutputStream();
	    GZIPOutputStream gzip = new GZIPOutputStream(obj);
	    gzip.write(str.getBytes("UTF-8"));
	    gzip.flush();
	    gzip.close();
	    return obj.toByteArray();
	  }

	  public static String decompress(final byte[] compressed) throws IOException {
	    final StringBuilder outStr = new StringBuilder();
	    if ((compressed == null) || (compressed.length == 0)) {
	      return "";
	    }
	    if (isCompressed(compressed)) {
	        final GZIPInputStream gis = new GZIPInputStream(new ByteArrayInputStream(compressed));
	        final BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(gis, "UTF-8"));

	        String line;
	        while ((line = bufferedReader.readLine()) != null) {
	          outStr.append(line);
	        }
	      } else {
	        outStr.append(compressed);
	      }
	      return outStr.toString();
	    }

	    public static boolean isCompressed(final byte[] compressed) {
	      return (compressed[0] == (byte) (GZIPInputStream.GZIP_MAGIC)) && (compressed[1] == (byte) (GZIPInputStream.GZIP_MAGIC >> 8));
	    }
        		
}
