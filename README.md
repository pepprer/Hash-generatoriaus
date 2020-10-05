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
    * [oneSymbol1.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/oneSymbol1.txt) **Hash'as:** 18a205e1a24b493c469f85e68c43708a627818f633a7a4318c6c1646e3e8f630
    * [oneSymbol2.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/oneSymbol2.txt) **Hash'as:** 6476537546764357646543464765475454654765333447653555666537543343
    
2. Du failai sudaryti iš daugiau nei 1000 atsitiktinai sugeneruotų simbolių:
    * [1001Symbols1.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/1001Symbols1.txt) **Hash'as:** a80707ad6811e2a022e8b7e4108d4e028560aa6aa45845aa28aa4451287888ac
    * [1001Symbols2.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/1001Symbols2.txt) **Hash'as:** 1b93cb6131292aa7e487399b887757978468247527586a0285418f83a88125f1
    
3. Du failai sudaryti iš daugiau nei 1000 simbolių, bet skiriasi vienu nuo kito tik vienu simboliu:
    * [1001Symbols3.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/1001Symbols3.txt) **Hash'as:** d424686e276c82286a664aa860ea94545c47134288e2877eca5145975599ac4c
    * [1001Symbols4.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/1001Symbols4.txt) **Hash'as:** e49084a1018a563fb1a1027a0861c8d295947a2641984ee195326e3415bb2121

4. Tuščias failas:
    * [emptyFile.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/emptyFile.txt) **Hash'as:** 2f5d9d5225e3f9be9540e68a932a3f4941b8213241909f0433e3507af383af7b
    
5. Efektyvumas:
    * Hash'uojama kiekviena eilutė iš [konstitucija.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/konstitucija.txt) šią funkciją ir SHA-256
    * Abi funkcijos turi tas pačias sąlygas
    * Matuojamas laikas:
        * SHA-256 - **0.0020221s**
        * Šitą funkciją - **0.0049952s**
        
6. 100 000 atsitiktinių simbolių eilučių porų: 
    * 25 000 porų, kurių ilgis - **10 simbolių:**
        * [check25k10Symbols.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/check25k10Symbols.txt) - **Kolizijų skaičius: 0**
    * 25 000 porų, kurių ilgis - **100 simbolių:**
        * [check25k100Symbols.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/check25k100Symbols.txt) - **kolizijų skaičius: 0**
    * 25 000 porų, kurių ilgis - **500 simbolių:**
        * [check25k500Symbols.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/check25k500Symbols.txt) - **Kolizijų skaičius: 0**
    * 25 000 porų, kurių ilgis - **1000 simbolių:**
        * [check25k1000Symbols.txt](https://github.com/pepprer/Hash-generatorius/blob/master/documents/check25k1000Symbols.txt) - **Kolizijų skaičius: 0**
        
7. [100 000 atsitiktinių simbolių eilučių porų](https://github.com/pepprer/Hash-generatorius/blob/master/documents/porosStringu.txt), 32 simbolių eilučių ilgiu, juos skiria tik vienas simbolis. Įvertinamas gautų hash'ų procentinis "skirtingumas" bitų
   lygmenyje:
    * Bitų lygmenyje:
        * Minimali skirtingumo reikšmė: **7.8125%**
        * Maksimali skirtingumo reikšmė: **41.4062%**
        * Vidurinė skirtingumo reikšmė: **25.2986%**
    * Hash'o lygmenyje:
        * Minimali skirtingumo reikšmė: **42.1875%**
        * Maksimali skirtingumo reikšmė: **100%**
        * Vidurinė skirtingumo reikšmė: **88.1281%**

### Norint paleisti kažkokį testą iš pateiktų aukščiau atidarykite failą **main.cpp** ir į funkciją **main** parašykite:
1. :heavy_check_mark: **Test().filesWithOneSymbol();**
2. :heavy_check_mark: **Test().filesWithMoreThan1000Symbols();**
3. :heavy_check_mark: **Test().filesWithMoreThan1000SymbolsOneWithOneDif();**
4. :heavy_check_mark: **Test().emptyFile();**
5. :heavy_check_mark: **Test().checkKonstitucija();**
6. 
   * :heavy_check_mark: **Test().check25k10Symbols();**
   * :heavy_check_mark: **Test().check25k100Symbols();**
   * :heavy_check_mark: **Test().check25k500Symbols();**
   * :heavy_check_mark: **Test().check25k1000Symbols();**
7. :heavy_check_mark: **Test().checkInBits();**

### Išvados:
   * Stiprybės:
      * Greitas šifravimas
      * Atstatyti išėjimą į įėjimą neįmanoma
      * Funkcija yra deterministinė
      * Minimalus įėjimo pakeitimai apsoliučiai pakeičia išėjimą
      * Praktiškai neįmanoma surasti tokių dviejų skirtingų argumentų, kad jiems gautume tą patį hash'ą
   * Trūkumai:
      * Hash'o ilgis
      

