
#include "user/analyse.h"
#include "useful/kout.h"
#include "useful/cpu.h"

/** \brief 
 *    \~english analyse function for exception
 *    \~german  Funktion zur Analyse einer Fehlerbehandlungsroutine.
 * 
 * \~
 * \param[in] slot
 *   \~english
 *   This is the interrupt ID, hence the same parameter as \ref guardian.
 *   \~german
 *   Dies ist die ID des Interrupts, wie er auch der Funktion \ref guardian übergeben worden wäre.
 * 
 * \~
 * \param[in] esp
 *   \~english
 *   This is the pointer to the top of the stack as it would be at the start of function
 *   \ref handleException. No code of the function is been executed thus the esp is in a status
 *   of never touched by the function itself.
 *   \~german
 *   Dieser Zeiger geht auf den Anfang des Stacks, wie er beim Aufruf der Funktion 
 *   \ref handleException wäre. Zu dem festgehaltenem Zeitpunkt wurde zwar die Funktion schon 
 *   aufgerufen, es wurde aber noch keine einzige Zeile abgearbeitet. Die Funktion selber hat
 *   den Stack also noch nicht verändert.
 *   
 *   
 * \~
 * \todo \~german den markierten ToDo-Bereich ausfüllen \~english fill in the todo area
 */
void analyseException(unsigned short slot, void** esp){
  //Ausgabe, was passiert ist
  kout << endl;
  kout << "analyseException(" << slot << ", " << esp << ") called" << endl;
  
  /* * * * * * * * * * * * * * * * * * *\
  # Start ToDo-Bereich                  #
  \* * * * * * * * * * * * * * * * * * */
  for(int i=0; i<6; i++)
  {

	  kout << hex << *esp++ << endl;
  }
  //traplist
  switch (slot) {
	  case 0: kout << "Division-by-zero" << endl; break;
	  case 1: kout << "Debug exception" << endl; break;
	  case 2: kout << "Non-Maskable Interrupt (NMI)" << endl; break;
	  case 3: kout << " Breakpoint (INT 3)" << endl; break;
	  case 4: kout << " Overflow" << endl; break;
	  case 5: kout << " Bound exception" << endl; break;
	  case 6: kout << " Invalid Opcode" << endl; break;
	  case 7: kout << " FPU not available" << endl; break;
	  case 8: kout << " Double Fault" << endl; break;
	  case 9: kout << " Coprocessor Segment Overrun" << endl; break;
	  case 10: kout << " Invalid TSS" << endl; break;
	  case 11: kout << " Segment not present" << endl; break;
	  case 12: kout << " Stack exception" << endl; break;
	  case 13: kout << " General Protection" << endl; break;
	  case 14: kout << " Page fault" << endl; break;
	  case 15: kout << " Reserved" << endl; break;
	  case 16: kout << " Floating-point error" << endl; break;
	  case 17: kout << " Alignment Check" << endl; break;
	  case 18: kout << " Machine Check" << endl; break;
	  default: kout << "Reserved by Intel" << endl;
	break;
}
	  
  
  /* * * * * * * * * * * * * * * * * * *\
  #  Ende ToDo-Bereich                  #
  \* * * * * * * * * * * * * * * * * * */
  
  //und anhalten, damit nichts schlimmes passiert
  cpu.disable_int();
  cpu.halt();
}


/** \brief 
 *    \~english analyse function for procedure stack
 *    \~german  Diese Funktion dient der Analyse des Prozedurstacks.
 * 
 * \~english
 * The functions prints the first 60 32 bit words of the stack, 
 * four of them in one line, each.
 * \~german 
 * Es werden die ersten 60 32-Bit-Worte vom Stack ausgegeben. Dabei 
 * erscheinen je vier der Worte in einer Zeile.
 * 
 * \~
 * \param[in] esp
 *   \~english
 *   This is a pointer to the top of the stack as it would be in function \ref alphaAckermann
 *   of task3B.cc before calling gotoAnalyse.
 *   \~german
 *   Dis ist ein Zeiger auf den Anfang des Stacks. Er ist aufgebaut, wie kurz 
 *   vor dem Aufruf der Funktion gotoAnalyse innerhalb von \ref alphaAckermann in 
 *   der Datei task3B.cc. Auf diese Weise kann der Prozedurstack gut analysiert werden.
 * 
 * \~
 * \todo \~german Funktion fuer Analyse ausfuellen. \~english fill in todo area
 */
void analyseProcedureStack(void** esp){
  //Ausgabe, was passiert ist
  kout << endl;
  kout << "analyseProcedureStack(" << esp << ") called" << endl;
  
  /* * * * * * * * * * * * * * * * * * *\
  # Start ToDo-Bereich                  #
  \* * * * * * * * * * * * * * * * * * */
  int i=0;
  for(i; i<60;i++)
  {
      if(i%4==0 && i!=0)
      {
          kout<<endl;
      }
      kout << hex << *(esp+i) <<" ";

  }
  kout<<endl;
  
  /* * * * * * * * * * * * * * * * * * *\
  #  Ende ToDo-Bereich                  #
  \* * * * * * * * * * * * * * * * * * */
} 
