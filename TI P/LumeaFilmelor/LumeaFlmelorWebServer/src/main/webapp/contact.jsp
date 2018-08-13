<%@ page contentType="text/html; charset=UTF-8" %> 
<div id="content">
  <div class="line-hor"></div>
  <div class="box">
    <div>
      <div >
        <div class="inner">
          <h3>Date de <span>Contact</span></h3>
          <div class="address">
            <div class="fleft"><span>Zip Code:</span>700259<br />
              <span>Țară:</span>România<br />
              <span>Telefon:</span>0754 023 154<br />
              <span>Fax:</span>+354 5635610
            </div>
            <div class="extra-wrap">
              <p style="font-size: 30;color:white;margin-bottom: -38px;">Informații utile:</p>
              <p class="detalii"> Vă rugăm să ne trimiteți orice sugestie sau problemă în legătură cu site-ul nostru. Echipa noastră este disponibilă 24/24. Dacă aveți întrebări sau probleme urgente vă rugăm să ne contactați telefonic, în caz contrar puteți completa formularul de mai jos:</p>
            </div>     
          </div>
        </div>
      </div>
    </div>
  </div>
  <div class="content">
    <div class="box2">
    <div class="movie-contact">
      <div class="content">  
        
        <h3>Formular de <span>Contact</span></h3>
        <form name="contact" action='Contacts' onsubmit="return validare()" method='post'>
          <div class="eroareVContact" id="eroareV" ></div>
          <fieldset id="contacts-form">
            <div class="field">
              <label>Nume:</label>
              <input type="text" name="nume" placeholder="Ex: Nume" value=""/>
            </div>
            <div class="field">
              <label>E-mail:</label>
              <input type="emails" name="mail" placeholder="Ex: aa@aa.com"  value=""/>
            </div>
            <div class="field">
              <label>Mesajul dumneavoastră:</label>
              <textarea cols="1" rows="1" name="mesaj"></textarea>
            </div>
          </fieldset>

          <div>  <input class="sendC" type="submit"><span><span></span></span></div>
        </form>
      </div>
    </div>
    </div>
  </div>