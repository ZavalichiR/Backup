package thread;

import java.util.Scanner;

public class FCFS
{
    public static void main(String[] args)
    {
        Thread id[]=new Thread[20];
        int btime[]=new int[20];
        int wtime[]=new int[20];
        int total=0;
        float avg;
        Scanner sn = new Scanner(System.in);
        System.out.print("\nNumar de threaduri: ");
        int n = sn.nextInt();
        for (int i=0;i<n;i++)      {
            System.out.println();

            id[i]=new Thread("Thread"+i);
            System.out.print("Burst time: "+(i+1)+" : ");
            btime[i]=sn.nextInt();
        }
        wtime[0]=0;
        for (int i=1;i<n;i++)      {
            wtime[i]=wtime[i-1]+btime[i-1];
            total=total+wtime[i];
        }
        avg=(float)total/n;
        System.out.println("\nProcess_ID\tBurst_time\tWait_time");
        for(int i=0;i<n;i++)
        {
            System.out.println(id[i].getName()+"\t\t"+btime[i]+"\t\t"+wtime[i]);
        }
        System.out.println("\nTimp total: "+total+"\nTimp mediu: "+avg);
        sn.close();



    }


}
