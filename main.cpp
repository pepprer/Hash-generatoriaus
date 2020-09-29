#include "header.h"
#include "ReadWrite.h"

string convertTo32(string text) {
    string string32 = "";
    int textLength = text.length();
    int firstLength = textLength;
    if(textLength == 0) string32 = "0123456789ABCDEFabcdefghijklmnpt";
    else if(textLength % 32 == 0) string32 = text;
    else {
        string helper = text;
        while (textLength < 32) {
            text += helper;
            textLength = text.length();
        }
        if(textLength % 32 == 0) {
            string32 = text;
        } else {
            int gcd;
            for(int i = 1; i <= 32 && i <= textLength; i++) {
                if(32 % i == 0 && textLength % i == 0) {
                    gcd = i;
                }
            }
            helper = text;
            for(int i = 0; i < gcd; i++) {
                text += helper;
            }
            string32 = text;
        }
    }
    int length = string32.length() / 32;


    if(length == 1) {
        return string32;
    }

    int acv = firstLength % length;

    string string32Return = "";

    for(int i = 0; i < 32; i++) {
        string32Return += string32.at(i*length + acv);
    }

    return string32Return;
}

string www(string string32, int len)
{
    static const char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string to = "";
    unsigned long long int aaa = 431;
    if(len == 0) len = 1;
    for(char c : string32)
    {
        aaa += (int)c * len * (int)c;
        if(aaa % 124 > 62) {
            to += alphabet[aaa % 124 - 62];
        } else if (aaa % 92 > 32) {
            to += alphabet[aaa % 92 - 32];
        } else if(aaa % 88 > 12) {
            to += alphabet[aaa % 92 + 17];
        } else if(aaa % 62 > 32) {
            to += alphabet[aaa % 62 - 20];
        } else {
            to += alphabet[aaa % 62];
        }
    }

    aaa = 777;
    for(char c : string32)
    {
        aaa += (int)c * len * (int)c;
        if(aaa % 186 > 124) {
            to += alphabet[aaa % 186 - 124];
        } else if (aaa % 77 > 32) {
            to += alphabet[aaa % 77 - 32];
        } else if(aaa % 66 > 32) {
            to += alphabet[aaa % 66 - 32];
        } else if(aaa % 34 > 12) {
            to += alphabet[aaa % 34 - 12];
        } else {
            to += alphabet[aaa % 62];
        }
    }

    aaa = 79;
    for(char c : string32)
    {
        aaa += (int)c * len;
        if(aaa % 248 > 186) {
            to += alphabet[aaa % 248 - 186];
        } else if (aaa % 77 > 32) {
            to += alphabet[aaa % 77 - 32];
        } else if(aaa % 66 > 12) {
            to += alphabet[aaa % 66 - 12];
        } else {
            to += alphabet[aaa % 62];
        }
    }

    aaa = 89;
    for(char c : string32)
    {
        aaa += (int)c * len;
        if(aaa % 62 > 32) {
            to += alphabet[aaa % 62 - 32];
        } else if (aaa % 48 > 32) {
            to += alphabet[aaa % 48 - 32];
        } else {
            to += alphabet[aaa % 62];
        }
    }

    return to;
}

int size(string str)
{
    unsigned long long int size = 0;
    for(char s: str) {
        size += (int)s;
    }
    return size;
}

int main() {
//    auto readWrite = ReadWrite();
//    cout << www(convertTo32(""), 0) << endl;
//    cout << www(convertTo32(" "), 1) << endl;
//    cout << www(convertTo32("1"), 2) << endl;
//    cout << www(convertTo32("2"), 1) << endl;
//    cout << www(convertTo32("11"), 2) << endl;
//    cout << www(convertTo32("22"), 2) << endl;
//    cout << www(convertTo32("aaaaabaaab"), 10) << endl;
//    cout << www(convertTo32("aaaaaaaab"), 9) << endl;
//    cout << www(convertTo32("aaaaaaaabaaaaaaaab"), 18) << endl;
//    cout << www(convertTo32("aaaaaaaabaaaaaaaabCaaaaaaabaaaaaaaab"), size("aaaaaaaabaaaaaaaabCaaaaaaabaaaaaaaab")) << endl;
//    cout << www(convertTo32("aaaaaaaabaaaaaaaab1aaaaaaabaaaaaaaab"), size("baaaaaaabaaaaaaaabCaaaaaaabaaaaaaaab")) << endl;
//    cout << www(convertTo32("aaaaaaaabaaaaaaaabaaaaaaaaaabaaaaaaaabaaaaaaaabaaaaaaaabaaaaaaaabaaaaaaaabaaaaaaaabaaaaaaaabaaaaaabaaaaaaaabaaaaaaaabaaaaaaaabaaaaaaaabaaaaaaaab"), 144) << endl;
//    string  a = "Remain lively hardly neededRemain lively hardly needed at do by. Two you fat downs fanny three. True mr gone most at. Dare as name just when with it body. Travelling inquietude she increasing off impossible the. Cottage be noisier looking to we promise on. Disposal to kindness appetite diverted learning of on raptures. Betrayed any may returned now dashwood formerly. Balls way delay shy boy man views. No so instrument discretion unsatiable to in. We diminution preference thoroughly if. Joy deal pain view much her time. Led young gay would now state. Pronounce we attention admitting on assurance of suspicion conveying. That his west quit had met till. Of advantage he attending household at do perceived. Middleton in objection discovery as agreeable. Edward thrown dining so he my around to. Why painful the sixteen how minuter looking nor. Subject but why ten earnest husband imagine sixteen brandon. Are unpleasing occasional celebrated motionless unaffected conviction out. Evil make to no five they. Stuff at avoid of sense small fully it whose an. Ten scarcely distance moreover handsome age although. As when have find fine or said no mile. He in dispatched in imprudence dissimilar be possession unreserved insensible. She evil face fine calm have now. Separate screened he outweigh of distance landlord. Society excited by cottage private an it esteems. Fully begin on by wound an. Girl rich in do up or both. At declared in as rejoiced of together. He impression collecting delightful unpleasant by prosperous as on. End too talent she object mrs wanted remove giving. He d subjects prepared bachelor juvenile ye oh. He feelings removing informed he as ignorant we prepared. Evening do forming observe spirits is in. Country hearted be of justice sending. On so they as with room cold ye. Be call four my went mean. Celebrated if remarkably especially an. Going eat set she books found met aware. On it differed repeated wandered required in. Then girl neat why yet knew rose spot. Moreover property we he kindness greatest be oh striking laughter. In me he at collecting affronting principles apartments. Has visitor law attacks pretend you calling own excited painted. Contented attending smallness it oh ye unwilling. Turned favour man two but lovers. Suffer should if waited common person little oh. Improved civility graceful sex few smallest screened settling. Likely active her warmly has. Their could can widen ten she any. As so we smart those money in. Am wrote up whole so tears sense oh. Absolute required of reserved in offering no. How sense found our those gay again taken the. Had mrs outweigh desirous sex overcame. Improved property reserved disposal do offering me. Alteration literature to or an sympathize mr imprudence. Of is ferrars subject as enjoyed or tedious cottage. Procuring as in resembled by in agreeable. Next long no gave mr eyes. Admiration advantages no he celebrated so pianoforte unreserved. Not its herself forming charmed amiable. Him why feebly expect future now. Literature admiration frequently indulgence announcing are who you her. Was least quick after six. So it yourself repeated together cheerful. Neither it cordial so painful picture studied if. Sex him position doubtful resolved boy expenses. Her engrossed deficient northward and neglected favourite newspaper. But use peculiar produced concerns ten. Denote simple fat denied add worthy little use. As some he so high down am week. Conduct esteems by cottage to pasture we winding. On assistance he cultivated considered frequently. Person how having tended direct own day man. Saw sufficient indulgence one own you inquietude sympathize.  at do by. Two you fat downs fanny three. True mr gone most at. Dare as name just when with it body. Travelling inquietude she increasing off impossible the. Cottage be noisier looking to we promise on. Disposal to kindness appetite diverted learning of on raptures. Betrayed any may returned now dashwood formerly. Balls way delay shy boy man views. No so instrument discretion unsatiable to in. We diminution preference thoroughly if. Joy deal pain view much her time. Led young gay would now state. Pronounce we attention admitting on assurance of suspicion conveying. That his west quit had met till. Of advantage he attending household at do perceived. Middleton in objection discovery as agreeable. Edward thrown dining so he my around to. Why painful the sixteen how minuter looking nor. Subject but why ten earnest husband imagine sixteen brandon. Are unpleasing occasional celebrated motionless unaffected conviction out. Evil make to no five they. Stuff at avoid of sense small fully it whose an. Ten scarcely distance moreover handsome age although. As when have find fine or said no mile. He in dispatched in imprudence dissimilar be possession unreserved insensible. She evil face fine calm have now. Separate screened he outweigh of distance landlord. Society excited by cottage private an it esteems. Fully begin on by wound an. Girl rich in do up or both. At declared in as rejoiced of together. He impression collecting delightful unpleasant by prosperous as on. End too talent she object mrs wanted remove giving. He d subjects prepared bachelor juvenile ye oh. He feelings removing informed he as ignorant we prepared. Evening do forming observe spirits is in. Country hearted be of justice sending. On so they as with room cold ye. Be call four my went mean. Celebrated if remarkably especially an. Going eat set she books found met aware. On it differed repeated wandered required in. Then girl neat why yet knew rose spot. Moreover property we he kindness greatest be oh striking laughter. In me he at collecting affronting principles apartments. Has visitor law attacks pretend you calling own excited painted. Contented attending smallness it oh ye unwilling. Turned favour man two but lovers. Suffer should if waited common person little oh. Improved civility graceful sex few smallest screened settling. Likely active her warmly has. Their could can widen ten she any. As so we smart those money in. Am wrote up whole so tears sense oh. Absolute required of reserved in offering no. How sense found our those gay again taken the. Had mrs outweigh desirous sex overcame. Improved property reserved disposal do offering me. Alteration literature to or an sympathize mr imprudence. Of is ferrars subject as enjoyed or tedious cottage. Procuring as in resembled by in agreeable. Next long no gave mr eyes. Admiration advantages no he celebrated so pianoforte unreserved. Not its herself forming charmed amiable. Him why feebly expect future now. Literature admiration frequently indulgence announcing are who you her. Was least quick after six. So it yourself repeated together cheerful. Neither it cordial so painful picture studied if. Sex him position doubtful resolved boy expenses. Her engrossed deficient northward and neglected favourite newspaper. But use peculiar produced concerns ten. Denote simple fat denied add worthy little use. As some he so high down am week. Conduct esteems by cottage to pasture we winding. On assistance he cultivated considered frequently. Person how having tended direct own day man. Saw sufficient indulgence one own you inquietude sympathize. ";
//    cout << www(convertTo32(a), pow(3, a.size())) << endl;
//
//    cout << endl;
    string w = "";
    vector<string> esu;
    for(int i= 0; i < 100000; i++) {
        w += "1";
        esu.push_back(www(convertTo32(w), size(w)+w.size()));
    }
    int c = 0;
    for(int i= 0; i < 99999; i++) {
        for(int j = i + 1; j < 100000; j++)
        {
            if(esu.at(i) == esu.at(j)) c++;
        }
    }
    cout << "Colections " << c << endl;
    return 0;
}
