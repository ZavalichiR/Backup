package lumeafilmelor.core;

public class ClientCinema {
	private String id;
	private String nume;
	private String prenume;
	private String telefon;
	private String locuri;
	private String scaune;
	
	public ClientCinema() {
		
	}
	public ClientCinema(String id,String nume, String prenume, String telefon, String locuri,String scaune) {
		this.id=id;
		this.nume=nume;
		this.prenume=prenume;
		this.telefon=telefon;
		this.locuri=locuri;
		this.scaune=scaune;
	}
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getNume() {
		return nume;
	}
	public void setNume(String nume) {
		this.nume = nume;
	}
	public String getPrenume() {
		return prenume;
	}
	public void setPrenume(String prenume) {
		this.prenume = prenume;
	}
	public String getTelefon() {
		return telefon;
	}
	public void setTelefon(String telefon) {
		this.telefon = telefon;
	}
	public String getLocuri() {
		return locuri;
	}
	public void setLocuri(String locuri) {
		this.locuri = locuri;
	}
	public String getScaune() {
		return scaune;
	}
	public void setScaune(String scaune) {
		this.scaune = scaune;
	}

}
