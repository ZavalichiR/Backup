package fcfs;

import java.util.Scanner;

public class FCFS
{
    public static void main(String[] args)
    {
        Thread id[]=new Thread[20];
        int btime[]=new int[20];
        int wtime[]=new int[20];
        int total=0;
        float media;
        
        Scanner citire = new Scanner(System.in);
        System.out.print("\nNumber of processes(maximum 20): ");
        int n = citire.nextInt();
        
        System.out.println("Process Burst Time: ");
        for (int i=0;i<n;i++)      {
            System.out.println();

            //id[i]=new Thread("Proces_"+i);
            id[i]=new Thread("P["+i+"]");
            System.out.print(id[i].getName()+": "); //P[i]:
            btime[i]=citire.nextInt();
        }
        wtime[0]=0;
        for (int i=1;i<n;i++)      {
            wtime[i]=wtime[i-1]+btime[i-1];
            total=total+wtime[i];
        }
        
        media=(float)total/n;
        System.out.print("\n----------------------------------------------");
        System.out.println("\n|Process  \tBurst Time\tWaiting Time |");
        for(int i=0;i<n;i++)
        {
            System.out.println("| "+id[i].getName()+"\t\t     "+btime[i]+"\t\t     "+wtime[i]+"       |");
        }
        System.out.print("----------------------------------------------");
        System.out.println("\nTimp total: "+total+"\nTimp mediu: "+media);
        citire.close();



    }


}
