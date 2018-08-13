package lumeafilmelor.core;

import java.sql.SQLException;
import java.util.List;


import lumeafilmelor.core.Contact;

public interface ContactDAO {
	List<Contact> getContacts() throws SQLException;

    Contact getContact(String name) throws SQLException;

    boolean addContact(Contact user) throws SQLException;
}
