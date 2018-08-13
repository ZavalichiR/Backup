package School;

import java.io.IOException;
import java.util.Scanner;

public class Main {

	private static Scanner in;

	public static void main(String[] args) throws IOException {
		in = new Scanner(System.in);
		int ok;
		System.out.println("Deschideti o clasa ?");
		System.out.println("1---DA");
		System.out.println("0---NU");
		ok = in.nextInt();
		while (ok == 1) {
			Clasa A = new Clasa();
			int std, teach;

			System.out.println("\n\n---------------A fost deschisa o noua clasa---------------");
			System.out.print("Profesori doritori: ");
			teach = in.nextInt();
			System.out.print("Studenti doritori: ");
			std = in.nextInt();
			for (int i = 0; i < std; ++i) {
				A.addStudent();
			}
			for (int i = 0; i < teach; ++i) {
				A.addTeacher();
			}
			A.closeRegistration();
			System.out.println("-------------------------------------------------------------\n\n");
			System.out.println("Deschideti o noua clasa ?");
			System.out.println("1---DA");
			System.out.println("0---NU");
			ok = in.nextInt();
		}

	}

}
