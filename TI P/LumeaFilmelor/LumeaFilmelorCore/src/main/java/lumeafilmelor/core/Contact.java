package lumeafilmelor.core;

public class Contact {
		private String nume;
		private String mail;
		private String mesaj;
		public Contact() {
			
		}
		public Contact(String nume, String mail,String mesaj)
		{
			this.nume=nume;
			this.mail=mail;
			this.mesaj=mesaj;
		}
		public void setNume(String nume) {
			this.nume = nume;
		}
		public void setMail(String mail) {
			this.mail = mail;
		}
		public void setMesaj(String mesaj) {
			this.mesaj = mesaj;
		}
		public String getNume() {
			return nume;
		}
		public String getMail() {
			return mail;
		}
		public String getMesaj() {
			return mesaj;
		}
		
}
