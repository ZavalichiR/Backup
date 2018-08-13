using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LumeaFilmelor
{
    public class Film
    {
        private int id;
        private String titlu;
        private String originalTitlu;
        private String gen;
        private String durata;
        private String limba;
        private String premiera;
        private String regizor;
        private String actori;
        private int an;
        private String descriere;
        private String trailer;
        private String imagine;

        public Film(int Id, String Titlu, String OriginalTitlu, String Gen, String Durata, String Limba, String Premiera, String Regizor, String Actori, int An, String Descriere, String Trailer, String Imagine)
        {
            this.id = Id;
            this.titlu = Titlu;
            this.originalTitlu = OriginalTitlu;
            this.gen = Gen;
            this.durata = Durata;
            this.limba = Limba;
            this.premiera = Premiera;
            this.regizor = Regizor;
            this.actori = Actori;
            this.an = An;
            this.descriere = Descriere;
            this.trailer = Trailer;
            this.imagine = Imagine;
        }

        public int getId()
        {
            return id;
        }

        public String getTitlu()
        {
            return titlu;
        }

        public String getOriginalTitlu()
        {
            return originalTitlu;
        }

        public String getGen()
        {
            return gen;
        }

        public String getDurata()
        {
            return durata;
        }

        public String getLimba()
        {
            return limba;
        }

        public String getPremiera()
        {
            return premiera;
        }

        public String getRegizor()
        {
            return regizor;
        }

        public String getActori()
        {
            return actori;
        }

        public int getAn()
        {
            return an;
        }

        public String getDescriere()
        {
            return descriere;
        }

        public String getTrailer()
        {
            return trailer;
        }

        public String getImagine()
        {
            return imagine;
        }

    }
}


