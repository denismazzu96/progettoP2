# progettoP2
Academic project for "Programmazione ad oggetti" course.
## Description
I've develop (one years ago) a simple library system in c++ using Qt5 as GUI library, i haven't use VCM or whatelse, just code and nothing else.
Documentation was written in Italian language and I haven't time to translate it, could be a future task.
## Getting started
### requirements
* GCC compiler, up to 5.3.0;
* Qt lib, up to 5.5.1;
* qmake and make commands avaiable from shell.
### usage example
Exec this commands to run the desktop application:
```bash
qmake -project
make
```
## Doc
### Scopo del progetto
Il progetto in esame consiste nel gestire una biblioteca dove utenti di diversa natura possono accedere (previa registrazione) e visualizzare, piuttosto che restituire o prendere in prestito i libri offerti dalla biblioteca in base al loro tipo di registrazione, inoltre l’applicazione offre possibilità di ricerca dei libri e di modifica dei dati personali. Per gli utenti saranno disponibili due tipi di registrazione, quella base e quella premium, la registrazione premium comporta l’inserimento di una carta di credito per il pagamento del canone e l’inserimento di un grado personalizzato, questo grado, più alto sarà, fino ad un massimo di 5, più libri si potranno visualizzare dal contenitore, l’amministratore è un’utente avanzato senza canone con grado massimo. Anche i libri si suddividono tra libri base, ovvero a grado minore (0), e libri premium caratterizzati dal grado, i libri visualizzabili, dal contenitore, per un utente x sono solo quelli che hanno il grado(libro) minore o uguale al grado(utente) di x. L’amministratore inoltre ha poteri su tutto l’applicativo potendo aggiungere, modificare o eliminare libri dal sistema e eliminare utenti, oltre ad essere l’unico a poter aggiungere altri amministratori, questa figura nell’ambito della biblioteca può essere vista come bibliotecario.
### Gerarchie di tipo per il modello
* Obj, classe base a livello più alto, definisce un’interfaccia comune per tutte quelle classi che definiranno oggetti del progetto, in essa è definito il distruttore di default virtuale.
* Persona, sottoclasse di Obj, definisce un oggetto di persona, qui si racchiudono tutti i parametri aggiuntivi di un’Utente.
* Utente, sottoclasse di Persona, definisce un’utente base definito da username e password, campi che definiscono univocamente un’utente nel sistema, l’Utente è il tipo a livello più basso (0) di registrazione possibile, l’operatore di uguaglianza ritorna vero se e solo se username e password hanno un match completo, in Utente è definita anche la lista dei libri in prestito dall’utente, inizializzata in maniera furba, ovvero solo quando richiesta, con tutti i metodi richiesti per la sua gestione, infine viene anche definito un metodo virtuale di ricerca molto banale per match completo tra la chiave di ricerca e titolo o autore del libro.
* UtenteAvanzato, sottoclasse di Utente, aggiunge ad un’Utente il campo grado che corrisponde al livello gerarchico all’interno della biblioteca (min= 1, max= 5), e il campo per il numero di carta di credito, servirà poi per far pagare un canone per questo tipo di registrazione, implementata nuovamente la funzione di ricerca per dare una profondità maggiore alla ricerca dei libri.
* Admin, sottoclasse di UtenteAvanzato a livello minore nella gerarchia di utenti, definisce
un UtenteAvanzato a livello massimo e senza il codice della carta di credito.
* AttributiLibro, sottoclasse di Obj, definisce attributi secondari per un Libro.
* Libro, sottoclasse di AttributiLibro, definisce un libro mediante la coppia autore libro, come per l’Utente due Libro o sottotipi ritornano vero, mediante l’operatore di uguaglianza, se e solo se autore e titolo hanno un match completo, in essa è racchiuso inoltre il campo per l’informazione del numero di copie disponibili.
* LibroMod, sottoclasse di Libro a livello minore nella gerarchia dei libri, aggiunge al libro il suo grado, ovvero il grado minimo che un Utente(o UtenteAvanzato) deve avere per avere accesso ad esso, un Libro di default ha grado 0 mentre un LibroMod può arrivare da 1 fino al grado 5.
* ContenitoreBase, sottoclasse templetizzata di std::vector che definisce funzionalità aggiuntive utili ad un contenitore per un tipo *T.
* Contenitore, sottoclasse di ContenitoreBase<T=Libro> serve ad implementare l’aggiornamento da/a file del contenitore, nel costruttore legge i libri dal file mentre nel distruttore aggiorna il file, solo se serve, inoltre son definiti metodi per bloccare o modificare questo aggiornamento automatico (definiti tra Contenitore e ContenitoreBase).
* ContenitoreUtenti, sottoclasse di ContenitoreBase<T=Utente>, duale a Contenitore ma per gli utenti.
* bad_admin, sottoclasse di std::exception che definisce l’eccezione chiamata quando ci si aspetta un’utente Admin ma si trova un diverso tipo di utente.
* bibl_expected, sottoclasse di std::exception, usata più nella parte fe (front-end) dove si richiede obbligatoriamente (un puntatore a) Biblioteca.
* global.h::std, namespace che racchiude varie funzionalità che gestiscono l’hashing degli oggetti, la crittografia della password, l’eliminazione di file ecc..
* Biblioteca, classe che definisce tutti i metodi che gestiranno la biblioteca, al suo interno si trovano
il riferimento del Contenitore principale dei libri e il riferimento all’utente loggato.
### Gerarchie di tipo per la GUI
* ApplicationCore, sottotipo di QObject, in ordine è la prima ad essere chiamata dal main.cpp, racchiude l’oggetto Biblioteca, gestisce inoltre il cambio di finestre.
* BWidget, sottotipo di QWidget, definisce un QWidget a cui serve il riferimento alla Biblioteca.
* Window, sottotipo di BWidget, gestisce il concetto di finestra, quindi non avrà nel costruttore il passaggio del parent come specificato nella doc di Qt per i QWidget finestra-
* LoginWindow, RegWindow, InfoWindow, sottoclassi di Window, che definiscono le varie interfacce banali per la GUI.
* MainWindow, anch’essa sottoclasse di Window, ma definisce la finestra principale dell’applicativo, come spiegato nel manuale della GUI più avanti, gestisce le tre fascie (Frame) principali.
* SearchBox, SetBookData, SetUserData, sottoclassi (secondarie) di Window, dentro risiedono tutte le interfacce secondarie spostate in finestre esterne per non appesantire troppo la visuale della MainWindow.
* UserFrame, BookFrame, sottoclassi di BWidget, che definiscono rispettivamente la parte GUI dell’utente e la GUI per i libri.
* AdminFrame, sottoclasse di BWidget, definisce la GUI dell’admin zone, divisa in due fasce, la superiore delle impostazioni utente composta dai due Box: LeftUserBox e RightUserBox, mentre la fascia inferiore delle impostazioni libro composta anch’essa dai due Box: LeftBookBox e RightBookBox.
* LeftBox, sottoclasse astratta di BWidget, che definisce un Box a sinistra, ovvero composta da una lista di elementi.
* RightBox, sottoclasse astratta di BWidget, che definisce un Box a destra, composto da un Form per l’aggiunta di elementi.
* LeftUserBox, LeftBookBox, sottoclassi concrete di LeftBox, definiscono rispettivamente l’aggiornamento della lista con i “giusti” parametri e le azioni da eseguire in caso di click (doubleClick) su elementi.
* RightUserBox, RightBookBox, sottoclassi concrete di RightBox, definiscono i From da utilizzare nei Box “a destra” e le azioni da eseguire per l’oggetto costruito dentro al Form.
* Form, sottoclasse di QWidget, definita per avere una base comune alle derivazioni di UserForm e BookForm.
* UserForm, BookForm, sottoclassi di Form, gestiscono la GUI del modulo per la costruzione di un utente e un libro rispettivamente.
* Message, classe che esegue un QMessageBox.
* WGlobal, classe che definisce i metodi di “conversione” da (puntatore a) Utente a QString e da (puntatore a) Libro a QString, oltre a definire la misura usata per alcuni QWidget a cui serve una lunghezza minima per una GUI migliore.
### Manuale utente GUI
L’applicazione tra il login e l’avvio mostra una finestra informativa per 5/8/10 secondi, a seconda della quantità di informazioni che deve mostrare, per facilitare l’uso dell’applicazione, se premuto invio si passa direttamente alla finestra successiva.
L’interfaccia grafica, escluse le finestre secondarie come quelle per il login o registrazione molto intuitive, si suddivide in un’unica finestra primaria sviluppata in due regioni, per utenti base e non, mentre si aggiunge un’ulteriore fascia se si accede al sistema come amministratore.
La prima area a sinistra racchiude la parte utente, mostrando i dati dell’utente acceduto e 4 pulsanti il cui che consentono, in ordine, di restituire tutti i libri, modificare i propri dati, uscire ed infine di eliminare il proprio account.
La parte centrale invece mostra la lista di tutti i libri a cui abbiamo accesso mediante il contenitore e la lista di tutti i libri ancora in nostro possesso, più sotto troviamo inoltre la barra di ricerca che permette di effettuare una ricerca sul contenitore, ricerca molto scadente se effettuata da un utente base invece molto migliore se effettuata dall’amministratore o da un’utente avanzato, i libri a cui un utente ha accesso son quelli con grado minore o uguale al grado dell’utente in questione, solo questi saranno visualizzati, se disponibili in quantità.
Infine la zona destra, la admin zone, è suddivisa in due fasce, quella superiore per la gestione degli utenti mentre quella inferiore per la gestione dei libri, nella fascia superiore troviamo una lista contenente gli utenti, utenti avanzati e amministratori del sistema che se premuti si potranno eliminare, e un modulo che permette la registrazione degli admin, non registrabili mediante il classico modulo di registrazione iniziale, si noti che esiste(finché non eliminato da un altro admin) un admin di default che ha come username “admin” e come password “admin”, questo amministratore viene creato ad ogni avvio del applicativo se non presente; nella fascia inferiore invece ci si occupa della gestione dei libri dove a sinistra la lista contenente i libri, che se premuti si dovrà decidere se eliminare o modificare, mentre a destra il modulo per l’inserimento di nuovi libri.
spesso i bottoni usati più frequenti sono stati settati come setAutoDefault(true) quindi con un tab e poi enter si simulerà il click del mouse.
In tutti i moduli presenti all’interno dell’applicazione tutti i loro campi sono a compilazione obbligatoria (se non specificato diversamente) altrimenti all’invio si perderanno i campi già compilati all’interno del modulo.
Il progetto sarà inizialmente vuoto se però si preferisce accedere con un sistema già avviato basterà spostarsi dentro “files/” e rinominare il file “~libri.txt” in “libri.txt”.
