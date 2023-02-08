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
Koncowki = {'usz':(486,-174,-311),'dzo':(-264,-77,341),'ela':(-108,-97,205),'iel':(-156,271,-115),'wej':(-121,-98,219),'ilo':(190,-165,-25),'ium':(530,-321,-209),'acy':(-141,-120,261),'zta':(-40,-190,231),'ele':(-209,134,75),'nik':(-135,268,-133),'usa':(624,-305,-319),'sza':(195,-22,-173),'eli':(-98,-66,164),'yli':(128,56,-184),'sie':(175,-92,-83),'tej':(-170,13,156),'tor':(-166,-216,383),'cem':(-78,169,-90),'owi':(184,-90,-93),'scy':(-130,245,-115),'kac':(46,113,-160),'ekl':(306,-79,-226),'nii':(411,-250,-160),'les':(191,-208,16),'bym':(-15,-218,233),'aty':(-182,249,-66),'nus':(647,-314,-333),'nic':(251,-169,-81),'ada':(-164,101,63),'dla':(-103,166,-63),'ero':(32,-290,258),'nak':(313,-333,20),'ena':(-293,536,-243),'che':(-168,-154,322),'erz':(-97,275,-178),'cje':(-215,-315,530),'arz':(-150,257,-106),'ely':(216,-77,-139),'owa':(-196,-3,199),'uje':(-81,-113,195),'ara':(581,-316,-265),'zas':(162,-27,-134),'bil':(-193,52,141),'ski':(-266,-78,345),'smy':(-123,-132,255),'man':(-312,-95,408),'emy':(8,-166,158),'dku':(-181,231,-50),'cej':(83,-177,93),'pie':(-202,23,179),'ral':(-93,188,-94),'ica':(-100,274,-174),'cow':(-41,214,-173),'oju':(-140,-175,315),'dza':(-140,227,-86),'awa':(-161,181,-20),'lby':(35,-161,126),'rci':(255,-122,-132),'sob':(-43,-224,268),'esc':(151,18,-169),'cji':(-81,-292,373),'mal':(173,-53,-119),'nku':(-91,200,-108),'zec':(203,-72,-131),'tus':(546,-274,-272),'arl':(-209,-244,453),'ady':(-87,200,-112),'ast':(149,-249,99),'yki':(192,-17,-174),'now':(169,-102,-66),'cki':(-310,-221,532),'jan':(647,-333,-313),'ewa':(-171,301,-130),'aki':(-277,454,-176),'awy':(-158,215,-56),'tka':(-204,21,183),'ies':(82,-199,116),'erc':(408,-202,-205),'aze':(-159,-75,235),'azy':(-225,464,-239),'cja':(-246,-258,504),'zek':(-239,150,88),'ecy':(-259,-233,492),'lam':(-205,-36,241),'bia':(-326,495,-169),'adz':(-259,476,-217),'zia':(-266,502,-236),'ent':(-288,154,134),'iat':(-267,-197,465),'epu':(-305,-223,528),'icz':(-322,101,220)}

# pre.py 60 70 -> 83 punkty
# pre.py 30 50 + Znaki -> 90 punktów
# pre.py 30 50 + Znaki (wszystkie litery osobno) -> 90 punktów
# pre.py 60 80 1000 160 (3-znakowe koncowki) -> 92 punkty
# pre.py 30 60 1300 40 (2-znakowe koncowki) -> ?

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

    ALPHA = 1.4

    for c in book:
        if ord(c) >= ord('A') and ord(c) <= ord('Z'): c = 'A'
        if ord(c) >= ord('a') and ord(c) <= ord('z'): c = 'a'
        if c in Znaki:
            S += Znaki[c][0] * ALPHA
            M += Znaki[c][1] * ALPHA
            P += Znaki[c][2] * ALPHA
    
    words = book.split()
    words = [''.join(filter(str.isalnum, s)) for s in words]
    words = [s[-3:] for s in words if len(s) >= 6]

    for s in words:
        if s in Koncowki:
            S += Koncowki[s][0]
            M += Koncowki[s][1]
            P += Koncowki[s][2]

    if S > M and S > P: return 'Sienkiewicz'
    if M > S and M > P: return 'Mickiewicz'
    if P > S and P > M: return 'Prus'

    return 'Sienkiewicz'

t = int(input())
for _i in range(t):
    s = input()
    a = who(s)
    print(a)