# Hash generatorius

Hash'avimo metu bet koks įvedimo tekstas (m) panaudojant (matematines) hash funkcijas: h = (m) 
yra paverčiamas unikaliu fiksuoto dydžio pseudo-atsitiktiniu skaičiumi, vadinamu maišos kodu.

### Programos paleidimas:

* git clone https://github.com/pepprer/Hash-generatorius.git
* Atidarykite projektą su Visual Studio arba JetBrains Clion
* Nustatykite: **Working directory** -> documents
* Paspauskite **Shift+F10** arba **Run**

### Programos publikacijos:

[v0.1](https://github.com/pepprer/Hash-generatorius/releases/tag/v0.1) versija:
1. Nuskaito failo pavadinima arba teksta is komandinės eilutės
2. Išveda į komandinę eilutę suhashota reikšmė
3. Leidžia paleisti testus

### Maišos funkcijos idėją pseudo-kodo stiliumi:
FUNCTION CRYPTSTRING(string32, size) <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;hashValue = "";

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;IF size == 0 THEN <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;size = 1; <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;END IF <br/>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;crypt = 43; <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FOR EACH s in string32 DO<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;crypt += (int) s * size * (int) s;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;IF crypt % 124 > 62 THEN <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;hashValue += alphabet[crypt % 124 - 62]; <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ELSE IF crypt % 92 > 32 THEN <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;hashValue += alphabet[crypt % 92 - 32]; <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ELSE IF crypt % 88 > 12 THEN <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;hashValue += alphabet[crypt % 92 + 17]; <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ELSE IF crypt % 62 > 32 THEN <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;hashValue += alphabet[crypt % 62 - 20]; <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ELSE <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;hashValue += alphabet[crypt % 62]; <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ENDIF <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;END FOREACH <br/>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;crypt = 777; <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FOR EACH s in string32 DO<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;crypt += (int) s * size * (int) s;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;IF crypt % 186 > 124 THEN <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;hashValue += alphabet[crypt % 186 - 124]; <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ELSE IF crypt % 77 > 32 THEN <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;hashValue += alphabet[crypt % 77 - 32]; <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ELSE IF crypt % 66 > 32 THEN <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;hashValue += alphabet[crypt % 66 - 32]; <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ELSE IF crypt % 34 > 12 THEN <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;hashValue += alphabet[crypt % 34 - 12]; <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ELSE <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;hashValue += alphabet[crypt % 62]; <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ENDIF <br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;END FOREACH <br/>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RETURN hashValue; <br/>
END FUNCTION
### Eksperimentinė analizė:

1. Du failai sudaryti tik iš vieno, tačiau skirtingo, simbolio:
    * [oneSymbol1.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/oneSymbol1.txt) **Šifras:** QHZrPen1JbtKTi3Ldv9OX5NfxlDS7PhzFB7hAHOVc3j7JT3AHlVL1vDVn3NHOVcp
    * [oneSymbol2.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/oneSymbol2.txt) **Šifras:** eKvfP9tZFirbL5VxdJnXH1BeKzjTDtZFXLlVFzjT258BEvfP9TWZcfiP5pZJ39B5
    
2. Du failai sudaryti iš daugiau nei 1000 atsitiktinai sugeneruotų simbolių:
    * [1001Symbols1.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/1001Symbols1.txt) **Šifras:** JhpWP7JmVh1aNRzPRrNHK7Nt1PHmTNPbHUfPJjfJJtUHDUJJbhJJDtU1r87X88JL
    * [1001Symbols2.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/1001Symbols2.txt) **Šifras:** QKYclkV1CQ2IBjz7NDXW3yIkhxWGEWy784v8b4W52GU8fZp2HeD1Ho8SZH8AR5o1
    
3. Du failai sudaryti iš daugiau nei 1000 simbolių, bet skiriasi vienu nuo kito tik vienu simboliu:
    * [1001Symbols3.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/1001Symbols3.txt) **Šifras:** mTBTVHfnR7FLhBbXvJFfdZJhFPNJIT5d5lT7acDBHxNBXG7NlJ5AT5Y75UI9ZLDL
    * [1001Symbols4.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/1001Symbols4.txt) **Šifras:** nTiPHTj1Pa8zE6cOkQZ1PRWjP8VALHmbyuI4GJrVTQyX4NNQIEcrFn3TQuKK2ab1
    
4. Tuščias failas:
    * [emptyFile.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/emptyFile.txt) **Šifras:** rOeM9mUbRuncOyKnYuDpNVHjYSRZCodiDQkhBQcRdQipYoPdCCN3e0WZOcHCZOWK
    
5. Efektyvumas:
    * Hash'uojama kiekviena eilutė iš [konstitucija.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/konstitucija.txt) šią funkciją ir SHA-256
    * Abi funkcijos turi tas pačias sąlygas
    * Matuojamas laikas:
        * SHA-256 - 0.0009968s
        * Šitą funkciją - 0.0019949s
        
6. 100 000 atsitiktinių simbolių eilučių porų: 
    * 25 000 porų, kurių ilgis - 10 simbolių:
        * [check25k10Symbols.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/check25k10Symbols.txt) - kolizijų skaičius: 0
    * 25 000 porų, kurių ilgis - 100 simbolių:
        * [check25k100Symbols.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/check25k100Symbols.txt) - kolizijų skaičius: 0
    * 25 000 porų, kurių ilgis - 500 simbolių:
        * [check25k500Symbols.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/check25k500Symbols.txt) - kolizijų skaičius: 0
    * 25 000 porų, kurių ilgis - 1000 simbolių:
        * [check25k1000Symbols.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/check25k1000Symbols.txt) - kolizijų skaičius: 0
        
7. 100 000 atsitiktinių simbolių eilučių porų, 32 simbolių eilučių ilgiu, juos skiria tik vienas simbolis. Įvertinamas gautų hash'ų procentinis "skirtingumas" bitų
   lygmenyje:
    * Minimali skirtingumo reikšmė: 50.3906%
    * Maksimali skirtingumo reikšmė: 76.3672%
    * Vidurinė skirtingumo reikšmė: 59.9649%

### Išvados:
