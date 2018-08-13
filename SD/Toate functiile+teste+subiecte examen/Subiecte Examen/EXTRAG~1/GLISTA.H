/****************************************************************
                      Fisierul GLISTA.H
*****************************************************************/
     typedef char Atom;
     enum { ATOM, LISTA};
     struct GElement;            // declaratie simpla
     typedef GElement* GLista;   // o lista generalizata este un
                                 // pointer la primul element 

     struct GElement{
            char tag;            // eticheta
            union {              // data poate fi
                Atom A;          //      Atom
                GLista L;        //  sau GLista
                } data;
	   GElement* link;        // legatura
           };                               

GLista creareGLista();
     // citeste si returneaza o lista generalizata data de la
     // intrarea standard, respectind sintaxa specificata.

