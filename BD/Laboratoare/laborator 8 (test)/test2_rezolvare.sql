-- 1
CREATE TABLE masini (
  id NUMBER(3),
  model VARCHAR(20),
  gama VARCHAR(20),
  marca VARCHAR(20),
  data_model DATE,
  CONSTRAINT masini_id_PK PRIMARY KEY (id),
  CONSTRAINT masini_data_model_CK CHECK (data_model>TO_DATE('01.01.2000', 'dd.mm.yyyy'))
);

-- 2
INSERT INTO masini VALUES (1, 'Logan', 'Break', 'Dacia', TO_DATE('01.06.2010', 'dd.mm.yyyy'));
INSERT INTO masini VALUES (2, 'MCV', 'SUV', 'Dacia', TO_DATE('13.02.2011', 'dd.mm.yyyy'));
INSERT INTO masini VALUES (3, 'Duster', 'SUV', 'Dacia', TO_DATE('03.05.2012', 'dd.mm.yyyy'));
INSERT INTO masini VALUES (4, 'Sandero', 'Hatchback', 'Dacia', TO_DATE('01.10.2008', 'dd.mm.yyyy'));
INSERT INTO masini VALUES (5, 'SLK55', 'AMG', 'Merceded', TO_DATE('01.01.2004', 'dd.mm.yyyy'));
INSERT INTO masini VALUES (6, 'prototip', NULL, 'Dacia', TO_DATE('01.09.2018', 'dd.mm.yyyy'));

SELECT marca, DECODE(gama, NULL, '*****', gama) AS "gama", model
FROM masini;

-- 3
SELECT DISTINCT(marca)
FROM masini;

SELECT model, gama, marca
FROM masini
WHERE model LIKE '%5%';

-- 4
SELECT *
FROM masini
ORDER BY marca ASC, data_model DESC;

-- 5
ALTER TABLE masini
MODIFY (model VARCHAR(20) CONSTRAINT masini_model_NN NOT NULL);

ALTER TABLE masini
MODIFY (marca VARCHAR(20) CONSTRAINT masini_marca_NN NOT NULL);

-- 6
CREATE TABLE masini_dacia
AS (SELECT *
    FROM masini
    WHERE marca='Dacia');
    
ALTER TABLE masini_dacia
ADD (data_lansare DATE);

-- 7
UPDATE masini_dacia
SET data_lansare=LAST_DAY(data_model);

-- SAU

INSERT INTO masini_dacia 
(SELECT id, model, gama, marca, data_model, LAST_DAY(data_model) FROM masini);

-- 8
SELECT marca, gama, model, 
	ROUND(MONTHS_BETWEEN(data_lansare, data_model), 2) AS "Nr. luni de la lansare"
FROM masini_dacia;

-- 9
SELECT marca || ' ' || gama || ' ' || model || ' -> ' || EXTRACT(YEAR FROM data_model) AS "Marca, gama si model -> an"
FROM masini;

DELETE 
FROM masini_dacia;
-- alternativ, TRUNCATE masini_dacia; dar nu e comanda DDL
