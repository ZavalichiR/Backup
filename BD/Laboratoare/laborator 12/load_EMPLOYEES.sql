ACCEPT first_name PROMPT 'Introduceti prenumele: ';
ACCEPT last_name PROMPT 'Introduceti numele: ';
ACCEPT salary PROMPT 'Introduceti salariul: ';

INSERT INTO MY_EMPLOYEE (first_name, last_name, userid, salary) 
	VALUES ('&first_name', '&last_name', SUBSTR('&first_name', 0, 1) || SUBSTR('&last_name', 0, 7), TO_NUMBER('&salary'));