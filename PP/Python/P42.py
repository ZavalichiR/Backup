
from statemachine import *

def cents_0(txt):
    split_txt = txt.split(None,1)
    if len(split_txt)>1:
        word, txt = split_txt
    else:
        (txt,"")
    if word == "Nickel":
        newState = "5_cents_deposited"
    else:
        newState = "10_cents_deposited"
    print("0 cents deposited")
    return (newState, txt)

def cents_5(txt):
    split_txt = txt.split(None,1)
    if len(split_txt)>1:
        word, txt = split_txt
    else:
        (txt,"")
    if word == "Nickel":
        newState = "10_cents_deposited"
    else:
        newState = "15_cents_deposited"
    print("5 cents deposited")
    return (newState, txt)

def cents_10(txt):
    split_txt = txt.split(None,1)
    if len(split_txt) > 1:
        word, txt = split_txt
    else:
        (txt,"")
    if word == "Nickel":
        newState = "15_cents_deposited"
    else:
        newState = "20_cents_or_more_deposited"
    print("10 cents deposited")
    return (newState, txt)

def cents_15(txt):
    split_txt = txt.split(None,1)
    if len(split_txt)>1:
        word, txt = split_txt
    else:
        (txt,"")
    if word == "Nickel":
        newState = "20_cents_or_more_deposited"
    else:
        newState = "15_cents_deposited"
    print("15 cents deposited")
    return (newState, txt)

def cents_20(txt):
    split_txt = txt.split(None,1)
    if len(split_txt)>1:
        word, txt = split_txt
    else:
        (txt,"")
    if word == "Nickel":
        newState = "5_cents_deposited"
    elif word == "Dime":
        newState = "10_cents_deposited"
    print("20 cents or more deposited")
    return ("20_cents_or_more_deposited","")


if __name__== "__main__":
    m = StateMachine()
    m.add_state("0_cents_deposited", cents_0)
    m.add_state("5_cents_deposited", cents_5)
    m.add_state("10_cents_deposited", cents_10)
    m.add_state("15_cents_deposited", cents_15)
    m.add_state("20_cents_or_more_deposited", None, end_state=1)
    m.set_start("0_cents_deposited")
    m.run("Dime Nickel Nickel Nickel Nickel Dime")
