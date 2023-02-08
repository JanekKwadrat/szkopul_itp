#!/usr/bin/python3

#  Jan Zakrzewski
#  XXVII Olimpiada Informatyczna, Etap II
#  Zadanie `Pisarze (pis)'

# Słowa, 4 pierwsze znaki
Sienkiewicz = 'PetrNeroOthoarbilaznretoinsuWatyLukaSeneoliwgemmAlbaMarkWiniAzjiwpussyneTybeKorbukonatleestePozdbogoRzymPoppbarbPorttuniPalaHerkmozaZeusbiblAgryWschCezaupewTrazRufiniszfaunlutndeklmasctoganozdAuluPlauPompLigiKallLigoAfroodkuHistlupiKlauGermGrectchnFeniEgipindzAferTygeAhentricsil,HelitogiEunijenotejzrzymJowiForuatrivelacubiwerwViculektwillwigiBrytItaltrzctarcAtenWenutogerybeNeapplytKastPollfletWsrowzbinaokKwirznadGrekwyspSeraznosbilinocezatySubulud,scepWiteflamChreKrystablzylyorazpilkZyciblusAntyKalwamfiBogoSaturzutBlogHomealabodblbezdmirtzalicytromdlzdacJaniZaliLibiKampcos,ukojzyliKornDianmiluAkteFortTeokNiegNazamisedrapKajuBoskzal,lkanAppiTak!zmilpeplUrsuorszCyprPawlTarsBiadnalobezszmagTerpmedrkranpoturozhpomsnamotwympchnsestUczyligiabysusprcnoczlymergaCzynspasolsnmekewam,ufnocudapodtKalijekismaghelmmigoobnamirrupojgdysTulibiodRubrbykaNigiAncjmorshymnobalDiodPitakagauroksyryswitratodressil.orgiwyziZaniBaiaLigabiecpiniZolnBarabiskLinubezeKaryAfryudacwezbPomoAtacwelnuzysHadezaultlokaugudeptmulyigrzzlyctchugaliTejrutwiChilszopsynuSenalud.Demazbralzy,JuniZbawGlauMerkTybrtratEuryOsticariCumaAchaBenesektObecPriaucznJakkZrozZatyKwarEmpoCyrkJudazewnUrbaukrzodpumekiAposSalaNomezaswdojsedyktessDrogfossmurezsta"ChrdechzwatowceMameTobizburMirimdlelodzbluzArycPromharfTroiPizoNerwEskwvivalwowdymodymyzgliFlawTullcuniChripodiCuchDoloNigeScew'
Mickiewicz = 'OjczBramludelonoSzergrykgrusbrzozewsstodgrzabrykganePodrKoncOglazdalczamPolsmocapadnRejtwnisalkoDabrmazuPeteochmnutyziolPolyBialWysmpuklwezewionwleczmrusianWojsWdzi"DobTadeStrysadyPodkzniwGospkragSpusboruNapewiazBlyssuwamawiEkonzytaCieswolyWesodozwpyluStadlecalakibiezutrugronNajloborWoznProtzamcizbaOknaHoregotyarchtem,WilnZmierefefilaSciasarnjelePolkbernBernzmowwodkwtenzwawjedlPustJakbRoztnadoDanoRozyogorRzekwegr"DziwnukWojemoscGrzemodnDawapuchWtenZwlaafekZnacmowytabamodaraptGadanosyOdbiKrzyswawchmirunaambochluWyjegaweorezwawrRoba"MniRykokwatRuskarmiGladdruzMajoPlutSuwalisapazuObacGorskregPosrwarklawyKrecpekilowyAsesRejeklotSokoKusetajnkruczwijnazbkraslicawzbrNazySoplflinszabbebnIlekleklGorzWszcSasiKogogalkwsieZwanwytksmyc"WyckurkdwursmykzagoKusySzaruche"Prasejmzadlwydrstrwpsia"ChaTelilowakich"WiwTabaknieodwozazyecheLachwojemniclowiDzikklowZadelowoTrafPuszHrecKrajRozbBrzelitykutamychdobyOginRymsGiedwywasad,zupa"UcilzacorlySlawRosySpadRodzrodaKniakedyskaknurkKsieMiercarszgonRozezestmszamszywydekarcbujadareOwdzwrobjastwojuwkramigapregklosskacgasiechoOdezrykipaserumacwalRuszCwalzlacPojeobydopokPedzUkazWiezsterblacZwalRomakon,GerwWkolPowtMopaRebaKlucUwiaChylkordSklografStolmopamaru"ZgoZsiazsiawnoswiwaKrolprymWiwaPogllowcJaceSzabOwozWasazieczagnKuchhajdtaralamuObroslanWzniruryzboj"MoswrotodsirapiScyzDwocpisktykakopcmeznNowazoczplocDrzekapuTam,kukulodykonozmijowadbadyliceplywSlomRekadzioczatnodzWascmignpszcRoznimbrfiliwicitrunmiodkabaWyrzcaraGodnKiryKozoStajRozsudobkozymarimospResznawzWstrustypajebzykzbadtylateginatrSzmeZdzilajazwadkapowslaostenizllasasuszsalaSangpyskswarWzieagrezleklopuWytkWymylacnkurypawiOdkrwiankoraNibyWisikitkDziaglasjagomodrpelzherolosoWycitonyZagaponoslomuwiakoneblawStapspicTamcgolaoponpioslikuOddagescChow*SwiZimnpstrDarmSchy"WidasckdociZlozWartzimyordeunizfraslosiZosiwacpJackZrazMalaIdziPonoostypanyUdajDobyNabrpejz"BrarysuuragLiteCzerUbraStoitopodebodasazzympalkkunsOrloilezulewChmuScisWysuCichRachryknniknPapizwinPorwDzwoOdglPelnobadskoksiwaDwiePiesrusktasa"StrPonaLezaWilezubrkolpJagimonasieklipaklodwymkszystanepniaZgadZnikhaslrubiwznaSkocWyskopetKedyKoraTrwaJankMuzyZawiSkolczubrodeKorosyzmWilbSkar"Oj,odarwascbakiPodhBirbGdanCesaBrzyPrusrdzakotlZajaWpadrazoUciechytzgratroppsiezmykChcaRyknlomuRwalzbilNatecetkwplawbitPijaruraSaga"TerDomeDowerureOdwacyngPodschruBuchflasbigoBierkwasprysZbroWstywyreWznonim;pjan"DosmetyZgodZbladygnsitorosoLeci"SedizbeObraPowsTrzaDaredarnkurchaniOdmicoryuchuoba,natarejtDenaNadabozyraneOzwaDotaPorzWskamaryciacZawoUrodOkrecwiedekrCofaSledskubTargMacizascwijaBydlbociwronslotSkrzguzyObmyBrachodobabiWojnwoziZalaPogopisnBiezoba.WidnszteBartMackgumnsero*RozmacaBronbojuWiatWynioczkGestTen,Grabszef"JenKlanHejzzwleKropSejm"KroKone"PredraghejzKlecwyucplusRozgaktasaznSzyd"Hejlisizatkjegrphu,SakazagicietZlak"ZdrrotaNikiszpo"MajSybicha,dukahulaSierJegrkosaGifrZebrfechRazePropdzidciecWalcRecepardroteRyceMazuserndrwaKrwicarenawabonoZofiBrzmPanedbamTeczpychImietyzeLaskzuraulanZdobomenzimedygaOfickupkJeneakor'
Prus = 'kupcKrakfirmMincWokufabrcygageniBismawankrytzdecwarifachradcWegrdwudsentsubizoniSzprajenmrukto?.ale.lat.pan.wtedHopfpiwopan?uczoWtedbufeNatuWcalPoszco..rezuprotakurbabarublrepupunkTurcanizmagamnozweksregumizelabochemIgnakanauleglustzgartylnbinonotaalbuStasCiekKlejMrackupolalksredduzebrunkantDoprstycfoteteorLisisalomorakalonumeAlezaleztlomdziugratprofinkaosmesnilfiglmechuscicyliPowoodciutopkwarZydkPalmEurokopemydlDomajejmtestpensco?.maz,cerepoufszufkaftdyscprynsytufizjodznKatzupomlat,ziewmanefunttutaparuLudwracjfaktMalgprakBulgwakazajrfutrskomCha!cha!kufeDomy?...serikundA...Leckkupubodaowszgruddrgnnic.no..PyszIzabkuzyFlorAleiUjazgabiMikoelekIstoKarolicyrewiAlejorygspecinzyzjezwagosympzainpapodywaarystriuopinwytwusuwideai...dystBelclibeBaroMeliKrzenikcmeblJoasszezBelupropsumynerwzirykoreplenzejdakcetak?komba!..otozszylopersufinie.Ach!ze..ten.naiwto..kozlfrazbaloadrekuflapatfataWislNowywejduniwSuzinosakomoDoktblotSkietak.wydzkupntam.metaMogedamekipipazdbynadzenZiebraz."MozZbliDalsMariMachHeluskancyniAle.Aha!paltparwja..PozedespPrezTrocsesjrok.KazibateaustbaluWegiklacwiorparohorylzejAle,JanoklapspryperkLaziStaceks-teleapetHenrdyrealeiumizhotetechMaruOchobaby!...BelaMisispazrejeZyd.YunganonKonsodegLiciomnigo..RossRomeOberwytoSzpiuspaChinLeonMageWirssystPatkbabcJumaGeisrasamediEwelWasobrekFeliNiwiMalbSzasRzezMoli'
# Częstości znaków
Znaki = {'':(1,-3,1),'.':(-96,-172,268),',':(9,56,-66),'"':(-165,213,-47),'?':(-104,-76,181),'!':(-93,122,-28),'-':(-60,-218,279),'A':(-69,116,-47),'a':(5,-1,-3)}
# Częstości końcówek
Koncowki = {'sz':(263,-141,-122),'il':(-15,41,-26),'le':(-39,43,-3),'ny':(-84,69,15),'zo':(-225,-63,289),'go':(9,-94,84),'la':(-4,-83,87),'lo':(93,-70,-23),'ly':(114,-30,-83),'ci':(57,-70,12),'el':(-189,145,44),'ch':(62,-17,-45),'ow':(-13,81,-68),'ej':(-18,-30,48),'um':(416,-283,-132),'lu':(-200,-37,238),'on':(84,-63,-20),'wy':(-91,110,-18),'no':(53,24,-78),'er':(-192,65,126),'ko':(-40,1,39),'cy':(-87,23,64),'ym':(33,-70,37),'ce':(32,36,-69),'ta':(-53,34,19),'ik':(-167,243,-76),'sa':(463,-252,-211),'sc':(142,-108,-34),'az':(-75,24,50),'zy':(14,66,-80),'za':(57,62,-119),'ni':(-7,73,-65),'im':(-117,107,10),'de':(10,-58,48),'en':(17,-117,99),'da':(-111,71,39),'ry':(-65,113,-47),'or':(-133,59,73),'us':(591,-299,-292),'dl':(-16,-69,85),'ic':(75,-17,-57),'sl':(79,-7,-72),'om':(35,66,-101),'ca':(-46,127,-80),'iu':(65,-108,42),'wi':(140,-38,-102),'ek':(-89,-3,92),'ka':(-91,61,30),'ki':(-192,18,173),'kl':(278,-86,-192),'ty':(-130,166,-36),'ii':(183,-276,92),'es':(68,-166,98),'dy':(-45,83,-37),'je':(-79,-60,139),'zi':(-91,69,21),'by':(73,-147,74),'ke':(-118,88,30),'ha':(-155,162,-6),'ro':(-38,-238,277),'yc':(47,-7,-40),'ru':(20,-78,57),'ja':(-111,89,22),'ak':(183,-209,26),'he':(-168,-154,322),'rz':(-92,238,-145),'ez':(-107,83,23),'ba':(-5,64,-58),'mu':(-92,-5,97),'am':(-48,-107,156),'te':(-30,65,-35),'wa':(-130,92,37),'du':(54,56,-111),'ra':(131,-63,-67),'to':(117,20,-138),'as':(152,-40,-111),'my':(-79,-78,157),'we':(-65,95,-29),'ku':(-93,132,-39),'gi':(-58,167,-108),'dz':(-68,188,-119),'zu':(54,1,-56),'ec':(43,-35,-8),'st':(185,-237,52),'si':(13,84,-97),'tu':(-37,-82,119),'nt':(-270,154,115),'et':(-155,-27,182),'ju':(-123,-23,147),'gl':(-52,-92,145),'at':(-166,-128,294),'ob':(-41,-227,268),'ol':(404,-228,-176),'ji':(-98,-218,317),'aj':(24,-52,28),'rl':(-209,-244,453),'od':(-70,101,-30),'ga':(-74,56,18),'yk':(-170,295,-124),'cz':(-119,119,0),'rc':(408,-202,-205),'pu':(-280,-213,493)}

# pre.py 60 70 -> 83 punkty
# pre.py 30 50 + Znaki -> 90 punktów
# pre.py 30 50 + Znaki (wszystkie litery osobno) -> 90 punktów
# pre.py 60 80 1000 160 (3-znakowe koncowki) -> 92 punkty
# pre.py 30 60 2000 40 (2-znakowe koncowki) -> ?

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
    words = [s[-2:] for s in words if len(s) >= 6]

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