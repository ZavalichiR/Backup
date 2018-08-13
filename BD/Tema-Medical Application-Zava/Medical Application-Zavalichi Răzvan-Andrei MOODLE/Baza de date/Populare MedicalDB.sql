INSERT INTO Nutritional (Id,Min,Max,Result,Conclusion) 
VALUES (1, 1 , 18.5 , "Subponderal", "Persoanele subponderale sunt la fel de expuse imbolnavirii de diabet ca si restul populatiei cu greutate normala sau supraponderali. Subponderalii sunt mai expusi riscului de osteoporoza si infectii comparativ cu persoanele cu greutate normala.");

INSERT INTO Nutritional (Id,Min,Max,Result,Conclusion) 
VALUES (2, 18.49, 25, "Normoponderal", "Orice exces de grasime este daunator, iar depasirea cu peste 20% a greutatii ideale va expune la riscuri serioase starea de sanatate a organismului.");

INSERT INTO Nutritional (Id,Min,Max,Result,Conclusion) 
VALUES (3, 24.9, 30, "Supraponderal", "Orice exces de grasime este daunator, iar depasirea cu peste 20% a greutatii ideale va expune la riscuri serioase starea de sanatate a organismului.");

INSERT INTO Nutritional (Id,Min,Max,Result,Conclusion) 
VALUES (4, 29.9, 35, "Obezitate moderata(grad I)", "Obezitatea este o cre?terea exagerata a greuta?ii corporale (peste 25% fa?a de greutatea normala), cauzata de acumularea unei cantita?i mari de grasime în ?esutul subcutanat ?i în jurul viscerelor.");

INSERT INTO Nutritional (Id,Min,Max,Result,Conclusion) 
VALUES (5, 34.9, 40, "Obezitate moderata(grad II)", "Obezitatea este o cre?terea exagerata a greuta?ii corporale (peste 25% fa?a de greutatea normala), cauzata de acumularea unei cantita?i mari de grasime în ?esutul subcutanat ?i în jurul viscerelor.");

INSERT INTO Nutritional (Id,Min,Max,Result,Conclusion) 
VALUES (6, 39.9 , 50, "Obezitate moderata(grad III)", "Obezitatea este o cre?terea exagerata a greuta?ii corporale (peste 25% fa?a de greutatea normala), cauzata de acumularea unei cantita?i mari de grasime în ?esutul subcutanat ?i în jurul viscerelor.");

INSERT INTO Nutritional (Id,Min,Max,Result,Conclusion) 
VALUES (7, 49.9, 100, "Superobezitate", "Obezitatea este o cre?terea exagerata a greuta?ii corporale (peste 25% fa?a de greutatea normala), cauzata de acumularea unei cantita?i mari de grasime în ?esutul subcutanat ?i în jurul viscerelor.");

select * from Nutritional;

INSERT INTO Patients (Id,FirstName, LastName, Gender, Phone, Weight, Height, Age ,Email, NId_fk) 
VALUES (17, "Razvan-Andrei", "Zavalichi", "Male", "0754 937 907", 80, 180, 22, "-", 2);

INSERT INTO Patients (Id,FirstName, LastName, Gender, Phone, Weight, Height, Age ,Email, NId_fk) 
VALUES (18, "Claudiu-Florin", "Zavalichi", "Male", "-", 78, 180, 24, "-", 2);

INSERT INTO Patients (Id,FirstName, LastName, Gender, Phone, Weight, Height, Age ,Email, NId_fk) 
VALUES (19, "Florin", "Padurariu", "Male", "-", 68, 178,	21,	"-",2);

INSERT INTO Patients (Id,FirstName, LastName, Gender, Phone, Weight, Height, Age ,Email, NId_fk) 
VALUES (20, "Ioana-Marina", "Ursan",	"Female", "-", 50, 167,	22,	"-",1);

INSERT INTO Patients (Id,FirstName, LastName, Gender, Phone, Weight, Height, Age ,Email, NId_fk) 
VALUES (24, "Tudor", "Marcu", "Male", "-", 78, 177, 22, "-", 2);

select * from Patients;

INSERT INTO Observations (Id,PId_fk,Nutritional_Obs,Medical_Obs) 
VALUES (12,17 ,"-","-");

INSERT INTO Observations (Id,PId_fk,Nutritional_Obs,Medical_Obs) 
VALUES (13,18 ,"-","-");

INSERT INTO Observations (Id,PId_fk,Nutritional_Obs,Medical_Obs) 
VALUES (14,19 ,"-","-");

INSERT INTO Observations (Id,PId_fk,Nutritional_Obs,Medical_Obs) 
VALUES (15,20 ,"-","-");

INSERT INTO Observations (Id,PId_fk,Nutritional_Obs,Medical_Obs) 
VALUES (19,24 ,"-","-");

select * from Observations;

INSERT INTO Diseases (Id, Disease, Conclusion) 
VALUES (19, "Fara", "Nu prezinta afectiuni");

INSERT INTO Diseases (Id, Disease, Conclusion) 
VALUES (22, "Hipertensiune", "Eliminarea adaosului suplimentar de sare in alimente sau la gatit..");

INSERT INTO Diseases (Id, Disease, Conclusion) 
VALUES (23, "Cardiopatie ischemica", "Se exclud cafeaua, stimulentele, zaharul si produsele zaharoase (prajituri, înghetata)...");
	
INSERT INTO Diseases (Id, Disease, Conclusion) 
VALUES (24,	"Diabet zaharat", "Se recomanda fructe proaspete ce vor fi consumate în cantitate limitata de doar 500 de grame pe zi...");
	
INSERT INTO Diseases (Id, Disease, Conclusion) 
VALUES (25,	"Refluxul gastroesofagian", "Se recomanda Supe și ciorbe de legume,Banane bine coapte,Migdale...");

select * from Diseases;

INSERT INTO Patients_Diseases (Id, PId_fk,DId_fk)
VALUES (102, 17, 22);
INSERT INTO Patients_Diseases (Id, PId_fk,DId_fk)
VALUES (114, 18, 19);
INSERT INTO Patients_Diseases (Id, PId_fk,DId_fk)
VALUES (115, 19, 1);
INSERT INTO Patients_Diseases (Id, PId_fk,DId_fk)
VALUES (116, 20, 19);
INSERT INTO Patients_Diseases (Id, PId_fk,DId_fk)
VALUES (117, 24, 1);

select * from Patients_Diseases;