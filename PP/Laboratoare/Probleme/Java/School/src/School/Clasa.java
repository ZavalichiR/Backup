package School;

public class Clasa {

	int numStd;
	int numTeach;
	Closed clasa;
	Superstate sup;
	Substate sub;
	
	public void addStudent() {

		if(numStd==10)
		{
			System.out.println("Sunt prea multi studenti. Nu se mai pot face inscrieri");
		}
		else
		{
			numStd=numStd+1;
		}
	}
	public void removeStudent() {

		numStd=numStd-1;
	}
	public void addTeacher() {

		numTeach=numTeach+1;
	}
	
	public void removeTeacher() {

		numTeach=numTeach-1;
	}
	public void closeRegistration() {

		if(numTeach==0)
		{
			sub=Substate.Unassigned;
			System.out.println("Nu sunt profesori( Substate Unassigned) ");
		}
		else
		{
			sub=Substate.Assigned;
			System.out.println("Sunt profesori( Substate Assigned) ");
		}
		
		
		if(sub==Substate.Unassigned)
		{
			sup=Superstate.closed;
			clasa=Closed.Cancelled;
			System.out.println("Clasa a fost inchisa( Superstate Closed/Cancelled) ");
		}
		
		
		if(sub==Substate.Assigned)
		{
			sup=Superstate.open;
			System.out.println("Clasa a fost deschisa( Superstate Open) ");
			if(numStd >= 3)
			{
				clasa=Closed.Committed;
				System.out.println("Sunt destui studenti. Clasa a fost acceptata");
			}
			if(numStd == 10)
			{
				clasa=Closed.Full;
				System.out.println("Sunt 10 studenti. Nu se mai pot face inscrieri");
			}
			if(numStd < 3)
			{
				clasa=Closed.Cancelled;
				System.out.println("Sunt prea putini studenti. Clasa nu a fost anulata");
			}
		}
		
		
		
		
	}
}
