package ceas;
import java.io.IOException;
import java.util.Scanner;
public class CeasSimplu{

	private static Scanner in;

	public static void main(String[] args) throws IOException, InterruptedException {
			Buton bt=new Buton();
			Baterie battery=new Baterie();
			in = new Scanner(System.in);
			
			System.out.print("----------------------------------------CEAS DIGITAL----------------------------------------\n");
			
			if(battery.ok==false)
			{
				
				System.out.println("Ceasul nu poate functiona fara baterie");
				System.out.println("    1---Introduc baterie");
				System.out.println("    0---Nu introduc baterie");
				System.out.print("          :r:");
				int introduc;
				introduc=in.nextInt();
				if(introduc==1)
				{
				battery.schimba();	
				int meniu =1;
				
				while(meniu==1)
					{
					System.out.println("\n\n\t\t------ECRAN------");
					System.out.println("\t\t 1---Afiseaza ora");
					System.out.println("\t\t 2---Schimba ora");
					System.out.println("\t\t 0---EXIT");
					System.out.println("\t\t-----------------");
					
					int setare;
					do{
						System.out.print("\t\t    :r: ");
						setare=in.nextInt();
					}while(setare<0 || setare >2);
					
					switch(setare)
						{
						case 0:
							meniu=0;
							break;
						case 1:
							bt.apasButon1si2();
							break;
						case 2:
							{
								int rel=1;
								while(rel!=4)
								{
									System.out.println("\n\t\t\t\t\t-------SETARI--------");
									System.out.println("\t\t\t\t\t1---Ora");
									System.out.println("\t\t\t\t\t2---Minunte");
									System.out.println("\t\t\t\t\t3---Secunde");
									System.out.println("\t\t\t\t\t0---Iesire din setari");
									System.out.println("\t\t\t\t\t---------------------");
						
									System.out.print("\t\t\t\t\t        :r: ");
									int c;
									c=in.nextInt();
									switch(c)
									{
									case 1:
									{
										bt.apasButon1();
										System.out.print("\nSetati ora: ");
										int n;
										n=in.nextInt();
										System.out.println("Se seteaza ora");
										for(int i=0;i<n;++i)
										{
											bt.apasButon2();
										}
										break;
									}
									case 2:
									{
										bt.contor=2;
										System.out.print("\nSetati minutele: ");
										int n;
										n=in.nextInt();
										System.out.println("Se seteaza minutele");
										for(int i=0;i<n;++i)
										{
											bt.apasButon2();
										}
										break;
									}
									case 3:
									{
										bt.contor=3;
										System.out.print("\nSetati secundele: ");
										int n;
										n=in.nextInt();
										System.out.println("Se seteaza secundele");
										for(int i=0;i<n;++i)
										{
											bt.apasButon2();
										}
										break;
									}
									case 0:
									{	
										rel=4;
										break;
									}
									}
								}	
							}
						}
					
					}
				
				}
				else
				{
					System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>EXIT<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
				}
			}
	}

}
