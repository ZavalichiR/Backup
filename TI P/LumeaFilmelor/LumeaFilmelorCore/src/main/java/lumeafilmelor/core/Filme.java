package lumeafilmelor.core;
import java.util.Date;

import javax.xml.bind.annotation.XmlRootElement;

public class Filme {

	private Integer id;
	private String titlu;  
    private String originalTitlu;
    private String gen;
    private String durata;
    private String limba;
    private String premiera;
    private String regizor;
    private String actori;
    private Integer an;
    private String  descriere;
    private String trailer;
    private String imagine;

    /**
     * !!! WARNING: A no argument constructor is required by the XML (de)serializer
     */
    public Filme() {
    }

    /**
     * 
     * @param username
     * @param password
     */
    public Filme( Integer Id, String Titlu, String OriginalTitlu, String  Gen, String Durata, String  Limba, String Premiera, String  Regizor, String Actori, Integer An, String  Descriere, String Trailer, String  Imagine) {
        super();
    	this.id=Id;
    	this.titlu=Titlu;  
        this.originalTitlu=OriginalTitlu;
        this.gen=Gen;
        this.durata=Durata;
        this.limba=Limba;
        this.premiera=Premiera;
        this.regizor=Regizor;
        this.actori=Actori;
        this.an=An;
        this.descriere=Descriere;
        this.trailer=Trailer;
        this.imagine=Imagine;
    }

	public Integer getId() {
		return id;
	}

	public String getTitlu() {
		return titlu;
	}

	public String getOriginalTitlu() {
		return originalTitlu;
	}

	public String getGen() {
		return gen;
	}

	public String getDurata() {
		return durata;
	}

	public String getLimba() {
		return limba;
	}

	public String getPremiera() {
		return premiera;
	}

	public String getRegizor() {
		return regizor;
	}

	public String getActori() {
		return actori;
	}

	public Integer getAn() {
		return an;
	}

	public String getDescriere() {
		return descriere;
	}

	public String getTrailer() {
		return trailer;
	}

	public String getImagine() {
		return imagine;
	}

	@Override
	public String toString() {
		return "Filme [id=" + id + ", titlu=" + titlu + ", originalTitlu=" + originalTitlu + ", gen=" + gen
				+ ", durata=" + durata + ", limba=" + limba + ", premiera=" + premiera + ", regizor=" + regizor
				+ ", actori=" + actori + ", an=" + an + ", descriere=" + descriere + ", trailer=" + trailer
				+ ", imagine=" + imagine + "]";
	}

   
	
    
    
    
}
