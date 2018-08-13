if __name__ == "__main__":
    # definim cele 5 stari ale automatului
    stari = ["0 cents deposited",  # starea 0
             "5 cents deposited",  # starea 1
             "10 cents deposited",  # starea 2
             "15 cents deposited",  # starea 3
             "20 cents or more deposited"   # starea 4
             ]

    # succesiunea starilor in functie de nickel sau dime
    tranzitii = [
        # din starea 0
        {
            "nickel": 1,  # cu intrarea "nickel" tranzitez in starea 1
            "dime": 2  # cu intrarea "dime" tranzitez in starea 2
        },
        # din starea 1, etc...
        {
            "nickel":  2,
            "dime": 3
        },
        {
            "nickel": 3,
            "dime": 4
        },
        {
            "nickel": 4,
            "dime": 4
        },
        {  # 4=stare finala
            "nickel": 1,
            "dime": 2  # ne intoarcem in starile 1 si 2
        }
    ]

    # citim starea initiala
    stare_initiala = input("Stare initiala: ")
    while stare_initiala not in range(0, 4):
        stare_initiala = input("Stare initiala: ")

    stare_curenta = stare_initiala
    print("Starea curenta este: %s" % stari[stare_curenta])
    print("Introduceti valori pentru monedele de introdus in automat: ")

    while True:
        val_moneda = input("0 - nickel, 1 - dime, 2 - parasire program  ")
        if val_moneda == 2:
            break
        elif val_moneda == 1:
            stare_curenta = tranzitii[stare_curenta]["dime"]
        elif val_moneda == 0:
            stare_curenta = tranzitii[stare_curenta]["nickel"]
        print("Starea curenta este: %s" % stari[stare_curenta])
