#!/usr/bin/python3

#  Jan Zakrzewski
#  XXVII Olimpiada Informatyczna, Etap II
#  Zadanie `Pisarze (pis)'

# Słowa, 4 pierwsze znaki
Sienkiewicz = 'PetrNeroarbicezaWatyLukaSenecypregipoliwAlbaMarkWiniAzjiTybeukonestebogoWitaRzymfaldPoppbarbPortgdymposyCharzrzutuniletnwykuPalaHerkzanuobfiZeusbiblmalpAgryWschCezabojeTrazRufifontfiollutnMilobostgrecilosnozdAuluPlauPompLigiKallLigoodkuHistKlauGrecfilotchnEgipluboTygeAhentrictogiEunijenomgnirzymJowiForuatricubiVicustokApollekttwegwillwigiodniBryttarcWenutogeryberybaNeapludndomanatoKastPollnaplfaleWsrowzbiczuwnaokfalaKwirGrekwyspznosSubuprefzamoTlumWitepoezKrystablcentAuguorazblusjakkamfiBogorzutodblmirtMiasczczzalicytrtez,zdacslicZalimlotSycyKamprojemienukojzyliCzemKornDianmiluAkteboluPomyNatoFortNiegNazapozdBosklkanAppimekaTak!splyzmilpeploporUrsuabymdopuorszCyprPawlTarsBiadnalobezsTerpInnymedrkranpotupomsnamocisntwympchnsestUczyligiabysmekeBozywam,ufnoNie!cudaKalijekismagklekoddemigonakaSercszmaTulibiodRubrAncjmorshymnoczowykazgaskagabezwswitratodreszemdwyzijuz,unikLigabiecBaraLinuKaryAfryudacAtacHadezaulaugumuroodnaoskaigrzPokocodztchugaliutwiChilszopMoglkopasynuDemazbraZbawGlauMerkcmenTybrtratEuryOsticariAchaBeneObecPaweucznZrozZatyKwarzewnUrbaukrzodpumekiAposNomenadlDrog"ChrPanaowceMirilodzTroiPizoNerwEskwlwowzgliFlawTullcuniChritrumpodiNigeScew'
Mickiewicz = 'LitwOjczludecudepagolesnSzerbursgrusSrodgajuSwiejesizewsstodWidaCzarbrykganegankkolkPodrfolwOglazdalKoscczamPolsDaleRejtObokStojPragwkolwnisalkoDabrmazukomnPeteochmNiedsukiziolponcdumaBialpuklwezeUjrzblonwionwleczmruWyszdanosianmodyWojsTadeStrysadyzjecPodkzniwCaleGospkragSpusboruCalywiazBlyssuwalaceEkonCieswolybokuszlydozwsludnawiowietlocStadlecalakibiezgronoborWoznProtKazazamcizbaDostpeklHorekadzZamkTrudarchtem,WilnSpraZmierefefilajelePolkIdacdamobernBernzmowlaciMezcwodkwtenzwawjedlJakbnadoDanoogorRzekwegr"DziwnukWojemoscdrudorzeGrzemodnDawapotapuchWtenZwlawniomowytaba"MojmodaOdbiKrzyubioswawPodcchmiJezdDosyrunaZakonateczlegaweorezwawrRobaRykobijearmipijekanodruzMajoPlutSuwapulklisapazuObacWesziskikregPosrwarkgalolawalawelawyKrecPoprlowyAsesRejeCoraklotSokoBralKusetajnzwijKolonazbkraslicaOgroChlowzbrNazySoplskapflinszabUstaIlekRownpedzWszcgalkSporklocwygiwytkpaznsmyc"WyckurkdwursmykzagoKusySkorkoziuche"PrasejmzadlkalewydrstrwLubipsiaogonTelilowarywadwakkich"WiwopraUmilknieodwozazyecheLachwojemniclowiDzikrogoZadeStrzlowoTrafPuszHrecKrajBrzemuchekonwywrmychdobyRymsMickzupaorlyZwycSlawhuczRosyRodzKniakedylasybagnskaknurkKsiecarszgonRozemszamszykarcbujaCzyldareskowOwdzwrobwiszrolimigapregsennklosskacgasiechoOdezindywezlponapaserumacwalRuszzlacobacPojePokaPedzUkazkonngrzystertecztumaRomasosnGerwWkolPowtMopalysiRebaKlucgrafStolmoj,mopa"ZgomowaturepasawnoswiwaKrolWiwamilakruzlowcJaceSzabOwozWasazagnKuchtaraWystmosklamuObrokuleslanwasaWzniruryzbojwrotodsirapiScyzDwoctykakopcTylezoczZapoObejplockapujarzTam,lodykonozmijowadlicemajostapRekadzioczatnodzWascWaszmignptasrokifaliRoznkawyfiliwicitrunmiodZabamowcczylPoloZabicarasrogNiezZwieRozsudobmospResznawzWstrplebSlycnatrucicRozkZdzizwadsiwewslaostewzganizllasasalaSangpyskswarwciszlekbokilopuWytkWymyWychkogulacnkurygesipawiTamtOdkrwiankoraNibyroguDziaglasjagomodrWycitonylasoZagawskrupatponopasislomsnopuwiakoneblawStapspicTamcgolaCiagzjadpioslikuOddaspow*SwichylUpadpstrDarmSchyasckZlozordelosiZosiwacpJackZrazIdziswatostypanyDobyglazpejz"BraLiteCzerUbradeboDlugdasazzympalkulectyczkunsilezIlezulewgradScisCichPochzwinPelnobadDwiePiesruskladuPonaGrozLezakolpwojosiekklodszysChwyZgadZnikhaslstukSkocopetKedyparzJankwsadMuzycymbSkolczubKoroWilbSkarodarwascPodhBirb"AleCesaJuzcBrzyPruswas,krailozamrowmestroba(jakZajaraniWpadUciechytzgrapsiezmykChcaZwroszyklapamaczmlynzablglabTysiruraDomeDowerurePodsBuchflaskwasprysbuchnajeWstyWznopjanZgodPodzdygntulitakt"SedizbePowsTrzaDarekurcwabiponuuchunaborejtWspoDenaNadaDotaPorzlewaZawoOkreukardekrCofaskubTargMaciuzbrzascwijaBydlslotPanuBrachodobabiWojnJozewoziPogopisnzranBiezBartMackgumnBronbojuWiatmiotKlanjazdKropKone"Predrag"ProwyucplusRozgakta"HejwzmazatkjegrSaka"Zdrmundszpo"MajSybicha,dukagitaJegrkosaGnieGifrZebrPropciecWalcrotebonoZofiulanzimeJene'
Prus = 'warskupcKrakfirmMincWokufabrAnglcygageniBismawanprezzdecwariradcWegrdwudpiwasubirestSzprajenhandmrukto?.siodale.lat.pan.wtedHopfdelipiwopan?uczoWtedNatutym.PoszrezuprotdyspakurbabarublrepupunkanizMimomagamnozkredweksmizelabochemIgnafirakanazeszulegubielusttylnbinonotaosiealbuStasCiekokniKlejMrackupolalksredduzebrunwbiekantporcDoprironstycfoteteorLisisalocenedoktszesmoranumenas.zdejAlezaleztlomodurZdajnogedziuprofinkaosmewegitydzfiglfantuscibrudPowoZydkPalmEuroOjcikopemydlDomaRaczjejmdaszdokumrugSwiapensdoczco?.obudmaz,cerezarupoufduzyprynsytufizjodznKatzupomlat,dni,ziewtutalekcparufamizepsSzwaLudwracjtygofaktMalgojceBulgturkzasyromaCha!cha!kufe?...PiecdrecA...Leckkupubodaserdowszockntak!grudnic.no..PyszIzabkuzyFlorAleigabiMikoelekIstoKarobilelicyorygmozlspecwagosympsferwyzypapoepokdemodywaarystriunajzopinwarukonkbaroideai...dystBelcBaroMeliKrzenikcmeblHeleszezsie?BelupropWyobnerwzirystlukoreplenzejdtak?a!..wytasufinie.ze..Tegonaiwto..frazkokifurmroczbaloadreapatWislNowywejduniwSuzinietnosakomoDoktblotSkieKobitak.Zydawydzkupntam.metapazddzenZiebraz.dajaMariMachHeluskanAle.doprAha!parwsekuja..ZasldespPrezTrocSposCoz,nudnsesjKazibateWegimileklacwiorparolajdlzejAle,spryLaziumowStaceks-teleapetHenrdyreMalesaleocenumizhoteintradwoMaruOchobabyBelaMisirejeZyd.YunganonKonsRossOberrolesumeSzpiLeonWirsPatkbabcJumaGeismediEwelWasobrekFelikowarydzMalbSzasRzezMoli'
# Częstości znaków
Znaki = {'':(1,-3,1),'.':(-96,-172,268),',':(9,56,-66),'"':(-165,213,-47),'?':(-104,-76,181),'!':(-93,122,-28),'-':(-60,-218,279),'A':(-69,116,-47),'a':(5,-1,-3)}
# Częstości końcówek
Koncowki = {'usz':(481,-172,-309),'olo':(-107,181,-73),'dzo':(-265,-74,339),'ela':(-115,-81,196),'sli':(194,0,-194),'nna':(-203,-195,398),'iel':(-153,268,-114),'ilo':(301,-195,-106),'ium':(530,-321,-208),'ogl':(253,-150,-103),'acy':(-128,-126,255),'ono':(75,84,-160),'lub':(319,-94,-224),'zta':(0,-189,188),'ele':(-175,168,6),'nny':(-158,-48,206),'nik':(-136,271,-134),'usa':(615,-296,-319),'ero':(305,-308,3),'zym':(205,-109,-96),'sza':(166,-7,-159),'ral':(-87,177,-89),'zas':(234,-120,-113),'ecz':(140,70,-211),'oda':(-89,181,-92),'now':(176,-38,-137),'aty':(-165,254,-88),'are':(-107,-99,206),'ekl':(161,-23,-137),'scy':(-133,251,-117),'les':(164,-181,17),'byc':(137,-223,85),'bym':(5,-192,187),'any':(-135,172,-37),'dza':(-101,198,-97),'ezy':(-110,229,-118),'nus':(648,-318,-329),'aby':(176,-144,-32),'zek':(-233,151,81),'awy':(-146,238,-91),'ron':(-222,-62,284),'owy':(-105,170,-65),'wet':(-57,-160,217),'tka':(-189,21,167),'nak':(259,-223,-35),'ena':(-258,500,-241),'cje':(-237,-319,556),'iat':(-53,-116,169),'ole':(-88,160,-71),'chy':(-71,200,-129),'jej':(147,-171,24),'mam':(-115,-76,192),'ely':(215,-74,-141),'ady':(-68,190,-121),'ako':(-1,243,-242),'osi':(-231,396,-164),'eci':(-93,162,-69),'zar':(585,-277,-308),'uje':(-79,-112,191),'ara':(358,-154,-203),'ani':(-195,-191,387),'eby':(-228,-62,290),'niz':(303,-130,-172),'awa':(-134,206,-71),'ski':(-242,-69,311),'smy':(-119,-109,228),'cej':(76,-169,93),'cka':(-206,273,-66),'edy':(-266,35,230),'twa':(-73,172,-99),'lbo':(-183,-49,233),'tad':(16,193,-210),'gie':(315,-131,-183),'gow':(260,-97,-162),'anu':(-243,-95,339),'ysl':(203,-181,-22),'pie':(-208,60,147),'gia':(639,-333,-306),'gii':(611,-323,-288),'ica':(-114,268,-154),'cow':(-47,223,-175),'oju':(-156,-83,240),'zki':(-160,164,-3),'hoc':(-168,226,-57),'lby':(68,-168,100),'Coz':(-292,-84,377),'sob':(-54,-208,263),'rod':(90,139,-229),'cji':(-102,-294,397),'nku':(-100,190,-90),'zec':(193,-62,-130),'arl':(-172,-213,385),'Jak':(-226,362,-135),'lam':(-188,-19,207),'cki':(-313,-227,541),'awe':(-166,260,-94),'ewa':(-200,328,-128),'emi':(-71,282,-210),'ecy':(-218,-228,447),'owu':(-280,59,221),'adz':(-144,255,-110),'azy':(-223,307,-83),'oru':(-210,309,-99),'Gdy':(-116,273,-156),'elu':(-147,-27,174),'bia':(-320,444,-123),'Juz':(-275,301,-25),'pan':(-328,-111,439),'zia':(-269,491,-222),'Pan':(-263,29,233)}

# pre.py 60 70 -> 83 punkty
# pre.py 30 50 + Znaki -> 90 punktów
# pre.py 30 50 + Znaki (wszystkie litery osobno) -> 90 punktów
# pre.py 60 80 1000 160 (3-znakowe koncowki) -> 92 punkty
# pre.py 30 60 2000 40 (2-znakowe koncowki) -> ?
# pre.py 60 80 1000 160 (3-znakowe koncowki, więcej wyrazów) -> 92 punkty

def unpack(book: str):
    l = len(book)
    ans = [book[i:i+4] for i in range(0, l, 4)]
    return ans

Sienkiewicz = set(unpack(Sienkiewicz))
Mickiewicz = set(unpack(Mickiewicz))
Prus = set(unpack(Prus))

def who(book: str)->str:
    '''kto jest autorem utworu, z którego pochodzi ten fragment'''
    S, M, P = 0, 0, 0
    
    words = book.split()
    words = [s[0:4] for s in words if len(s) >= 4]

    for s in words:
        if s in Sienkiewicz: S += 300
        if s in Mickiewicz: M += 300
        if s in Prus: P += 300

    if S > M and S > P: return 'Sienkiewicz'
    if M > S and M > P: return 'Mickiewicz'
    if P > S and P > M: return 'Prus'

    ALPHA = 2.5

    for c in book:
        if ord(c) >= ord('A') and ord(c) <= ord('Z'): c = 'A'
        if ord(c) >= ord('a') and ord(c) <= ord('z'): c = 'a'
        if c in Znaki:
            S += Znaki[c][0] * ALPHA
            M += Znaki[c][1] * ALPHA
            P += Znaki[c][2] * ALPHA
    
    words = book.split()
    words = [''.join(filter(str.isalnum, s)) for s in words]
    words = [s[-3:] for s in words if len(s) >= 3]

    for s in words:
        if s in Koncowki:
            S += Koncowki[s][0]
            M += Koncowki[s][1]
            P += Koncowki[s][2]

    if S > M and S > P: return 'Sienkiewicz'
    if M > S and M > P: return 'Mickiewicz'
    if P > S and P > M: return 'Prus'

    return 'Nieznane'

t = int(input())
for _i in range(t):
    s = input()
    a = who(s)
    print(a)