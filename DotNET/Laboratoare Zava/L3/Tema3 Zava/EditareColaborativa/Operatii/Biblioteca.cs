using System;

namespace BibliotecaClient
{
    [Serializable]
    public class Selectie
    {
        public int PozitieStart
        {
            get; set;
        }

        public int LungimeSelectie
        {
            get; set;
        }
        public Selectie()
        {
            PozitieStart = 0;
            LungimeSelectie = 0;
        }

        public Selectie(int pozitie, int lungime = 0)
        {
            PozitieStart = pozitie;
            LungimeSelectie = lungime;
        }
    }

    [Serializable]
    public class Operatie
    {
        public enum DenumireOperatie {OP_INSERARE, OP_STERGERE, OP_DEPLASARE, OP_VIDA, OP_SERVER};
        protected DenumireOperatie mOperatie;
        protected string mToken;
        protected Selectie mSelection;

        public string Token
        {
            get
            {
                return mToken;
            }
            set
            {
                mToken = value;
            }
        }

        public DenumireOperatie Denumire
        {
            get
            {
                return mOperatie;
            }
        }

        public Operatie()
        {
            mOperatie = DenumireOperatie.OP_VIDA;
        }
        public Operatie(DenumireOperatie op, string token)
        {
            mOperatie = op;
            mToken = token;
        }
        
    }

    [Serializable]
    public class OperatieInserare : Operatie
    {
        private string mInsertedText;
        public string InsertedText
        {
            get
            {
                return mInsertedText;
            }
            set
            {
                mInsertedText = value;
            }
        }

        public Selectie InsertPoint
        {
            get
            {
                return mSelection;
            }
            set
            {
                mSelection = value;
            }
        }

        public OperatieInserare (string token, string textInserat, Selectie pozitie) : this()
        {
            mInsertedText = textInserat;
            mSelection = pozitie; // O selectie de lungime 0
            mToken = token;
        }

        public OperatieInserare()
        {
            mOperatie = DenumireOperatie.OP_INSERARE;
        }
    }

    
    // Stergere - Inserare de text nul cu selectie nenula
    //[Serializable]
    //public class OperatieStergere : Operatie
    //{
    //    //Sterge un nr de caractere de langa cursor.
    //    //Pozitiv -> Sterge la stanga (backspace)
    //    //Negativ -> Sterge la dreapta (delete)
    //    private int mDeletedCharNum;
    //    public int DeletedChars
    //    {
    //        get
    //        {
    //            return mDeletedCharNum;
    //        }
    //        set
    //        {
    //            mDeletedCharNum = value;
    //        }
    //    }

    //    public OperatieStergere()
    //    {
    //        mOperatie = DenumireOperatie.OP_STERGERE;
    //    }

    //    public OperatieStergere(string token, int charNum) : this()
    //    {
    //        mDeletedCharNum = charNum;
    //        mToken = token;
    //    }

    //}

    [Serializable]
    public class OperatieDeplasare : Operatie
    {
        //Muta cursorul
        //Offset pozitiv -> dreapta
        //Offset negativ -> stanga
        

        public OperatieDeplasare()
        {
            mOperatie = DenumireOperatie.OP_DEPLASARE;
        }

        public OperatieDeplasare(string token, Selectie pozitieNoua) : this()
        {
            mSelection = pozitieNoua;
            mToken = token;
        }
    }

    [Serializable]
    public class OperatieServer : Operatie
    {
        // Operatii cu server-ul.
        // Operatiile posibile sunt:
        // -> Sincronizare (Conectare)
        // -> Deconectare
        public enum Operatii { SERV_CON, SERV_RELEASE, SERV_SYNC }

        public OperatieServer()
        {
            mOperatie = DenumireOperatie.OP_SERVER;
        }
        public OperatieServer(string token, Operatii op, Object data) : this()
        {
            OperatiuneServer = op;
            opData = data;
            mToken = token;
        }

        public Object opData; // Date diverse pentru operatiile suportate
        public Operatii OperatiuneServer;
    }

    [Serializable]
    public class StareClient
    {
        private int mPozitie;
        private string mToken;
        //private string mQueue;
        public int Pozitie
        {
            get
            {
                return mPozitie;
            }
            set
            {
                mPozitie = value;
            }
        }

        public string Token
        {
            get
            {
                return mToken;
            }
            set
            {
                mToken = value;
            }
        }

        public StareClient()
        {
            mPozitie = 0;
            mToken = "";
            //mQueue = null;
        }

        public StareClient(int pozitie, string token)
        {
            mPozitie = pozitie;
            mToken = token;
            //mQueue = null;
        }

       
       // public string QueuePath
       // {
       //     set
       //     {
       //         mQueue = value;
       //     }
       //} 
       
    }
}
