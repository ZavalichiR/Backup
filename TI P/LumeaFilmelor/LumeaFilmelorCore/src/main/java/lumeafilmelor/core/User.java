package lumeafilmelor.core;

import javax.xml.bind.annotation.XmlRootElement;

@XmlRootElement
public class User {

    private String    username;
    private String    password;

    /**
     * !!! WARNING: A no argument constructor is required by the XML (de)serializer
     */
    public User() {
    }

    /**
     * 
     * @param username
     * @param password
     */
    public User(String username, String password) {
        super();
        this.username = username;
        this.password = password;
    }

    public String getUsername()
    {
    	return this.username;
    }
    public String getPassword()
    {
    	return this.password;
    }
    
    public void setUsername(String username)
    {
    	this.username=username;
    }
    public void setPassword(String password)
    {
    	this.password=password;
    }
    /**
     * @param id
     * @param title
     * @param author
     * @param publisher
     * @param addedDate
     */

    

    /* (non-Javadoc)
     * @see java.lang.Object#toString()
     */
    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        builder.append("User [username=").append(username).append(", password=").append(password).append("]");
        return builder.toString();
    }
    
    

}
