#!/usr/bin/python3

#  Jan Zakrzewski
#  XXVII Olimpiada Informatyczna, Etap II
#  Zadanie `Pisarze (pis)'

Sienkiewicz = 'PetrNeroOthoarbilaznretoinsuWatyLukaSeneoliwgemmAlbaMarkWiniAzjiwpussyneTybeKorbPartukonatleestePozdbogoRzymBityHeraPoppbarbPorthypotuniPalaHerkmozaZeusbiblAgryWschCezaupewTrazRufiniszfaunust,lutnTedydeklunctmascgietvesttoganozdAuluPlauPompLigiKallLigoAfroodkuHistWannSweblupiHermKlaulupaGermGrectchnSoraFeniEgipindzAulaAferTygeAhentricsil,Heli"bosAlektogiEunijenotejzuniopranrzymJowiForuatrivelacubiwerwVicuOlbrlektwillwigiBrytItalLicytrzcirystarcAtenWenutogerybeNeapwydlplytKastPollfletWsrowzbinaokKwirGaloznadGrekwyspGaliSerapalmznosbilinocezatykrypSubuSekulud,OktascepzbrzWiteflamChreKrysimpltablWespzylyorazpilkZyciblusAntyKalwamfiBogoSaturzutBlogHomealabodblbezdmirtAnakzalicytromdlzdacJaniZaliLibiKampcos,ukojzyliKornDianmiluAkteFortTeokNiegumocNazamisedrapKajuHastBoskzal,lkanlaraAppiTak!zmilpeplUrsuorszCyprPawlTarsgorlBiadnalobezszmagTerpmedrkranobelpoturozhpomsnamotwympchnMilusestUczyligiabysbezkusprcnoczlymergaCzynspasolsnmekewam,ufnocudasen,podtzwilnumiupiepolbKalijekismaghelmmigozrosobnamirrupajupojgdysolimTulibiodRubrbykaNigiAncjmorshymnulgiSabiobalDiodPitakagauroksyryswitratodressil.orgiwyziZaniBaiazmroLigabiecpiniZolnBozaBaraJemubiskLinubezeKaryAfryudacwezbPomoAtacwelnalekuzysHadezaulkijatlokaugudeptKrewmulyigrzzlycsnu.tchugaliTejrutwiChilszopsynuroilSenalud.Demazbralzy,igraJuniZbawGlauMerkjaloTybrtratEuryOstiarcycariCumaAchaAmfiBeneAlitsektJudejawnObecPriaucznJakkZrozZatyKwarEmpoAwenCyrkJudazewnUrbaukrzodpumekiAposSalaNomezaswdojsOzyredykbog,tesspoobDrogwawofossmurehen,zsta"ChrdechzwatSynaowceMamedomkTobizburMirimdleLitolodzbluzpascArycPretPromharfOgieostoTroiOlimPizoNerwEskwosiavivalwowlwy,FaonUstrPozadymodymyCaelzgligineFlawJehomulaTullcuniChripodiKaleLaniCuchDoloCoriNigeScew'
Mickiewicz = 'OjczBramludelonoSzergrykgrusbrzozewsstodgrzabrykganePodrKoncOglazdalczamPolsmocapadnRejtwnisalkoDabrmazuPeteochmnutyziolPolyBialWysmpuklwezewionwleczmrusianWojsWdzi"DobTadeStrysadyPodkzniwGospkragSpusboruNapewiazBlyssuwamawiEkonzytaCieswolyWesodozwpyluStadlecalakibiezutrugronNajloborWoznProtzamcizbaOknaHoregotyarchtem,WilnZmierefefilaSciasarnjelePolkbernBernzmowwodkwtenzwawjedlPustJakbRoztnadoDanoRozyogorRzekwegr"DziwnukWojemoscGrzemodnDawapuchWtenZwlaafekZnacmowytabamodaraptGadanosyOdbiKrzyswawchmirunaambochluWyjegaweorezwawrRoba"MniRykokwatRuskarmiGladdruzMajoPlutSuwalisapazuObacGorskregPosrwarklawyKrecpekilowyAsesRejeklotSokoKusetajnkruczwijnazbkraslicawzbrNazySoplflinszabbebnIlekleklGorzWszcSasiKogogalkwsieZwanwytksmyc"WyckurkdwursmykzagoKusySzaruche"Prasejmzadlwydrstrwpsia"ChaTelilowakich"WiwTabaknieodwozazyecheLachwojemniclowiDzikklowZadelowoTrafPuszHrecKrajRozbBrzelitykutamychdobyOginRymsGiedwywasad,zupa"UcilzacorlySlawRosySpadRodzrodaKniakedyskaknurkKsieMiercarszgonRozezestmszamszywydekarcbujadareOwdzwrobjastwojuwkramigapregklosskacgasiechoOdezrykipaserumacwalRuszCwalzlacPojeobydopokPedzUkazWiezsterblacZwalRomakon,GerwWkolPowtMopaRebaKlucUwiaChylkordSklografStolmopamaru"ZgoZsiazsiawnoswiwaKrolprymWiwaPogllowcJaceSzabOwozWasazieczagnKuchhajdtaralamuObroslanWzniruryzboj"MoswrotodsirapiScyzDwocpisktykakopcmeznNowazoczplocDrzekapuTam,kukulodykonozmijowadbadyliceplywSlomRekadzioczatnodzWascmignpszcRoznimbrfiliwicitrunmiodkabaWyrzcaraGodnKiryKozoStajRozsudobkozymarimospResznawzWstrustypajebzykzbadtylateginatrSzmeZdzilajazwadkapowslaostenizllasasuszsalaSangpyskswarWzieagrezleklopuWytkWymylacnkurypawiOdkrwiankoraNibyWisikitkDziaglasjagomodrpelzherolosoWycitonyZagaponoslomuwiakoneblawStapspicTamcgolaoponpioslikuOddagescChow*SwiZimnpstrDarmSchy"WidasckdociZlozWartzimyordeunizfraslosiZosiwacpJackZrazMalaIdziPonoostypanyUdajDobyNabrpejz"BrarysuuragLiteCzerUbraStoitopodebodasazzympalkkunsOrloilezulewChmuScisWysuCichRachryknniknPapizwinPorwDzwoOdglPelnobadskoksiwaDwiePiesrusktasa"StrPonaLezaWilezubrkolpJagimonasieklipaklodwymkszystanepniaZgadZnikhaslrubiwznaSkocWyskopetKedyKoraTrwaJankMuzyZawiSkolczubrodeKorosyzmWilbSkar"Oj,odarwascbakiPodhBirbGdanCesaBrzyPrusrdzakotlZajaWpadrazoUciechytzgratroppsiezmykChcaRyknlomuRwalzbilNatecetkwplawbitPijaruraSaga"TerDomeDowerureOdwacyngPodschruBuchflasbigoBierkwasprysZbroWstywyreWznonim;pjan"DosmetyZgodZbladygnsitorosoLeci"SedizbeObraPowsTrzaDaredarnkurchaniOdmicoryuchuoba,natarejtDenaNadabozyraneOzwaDotaPorzWskamaryciacZawoUrodOkrecwiedekrCofaSledskubTargMacizascwijaBydlbociwronslotSkrzguzyObmyBrachodobabiWojnwoziZalaPogopisnBiezoba.WidnszteBartMackgumnsero*RozmacaBronbojuWiatWynioczkGestTen,Grabszef"JenKlanHejzzwleKropSejm"KroKone"PredraghejzKlecwyucplusRozgaktasaznSzyd"Hejlisizatkjegrphu,SakazagicietZlak"ZdrrotaNikiszpo"MajSybicha,dukahulaSierJegrkosaGifrZebrfechRazePropdzidciecWalcRecepardroteRyceMazuserndrwaKrwicarenawabonoZofiBrzmPanedbamTeczpychImietyzeLaskzuraulanZdobomenzimedygaOfickupkJeneakor'
Prus = 'kupcKrakfirmMincWokufabrcygageniBismawankrytzdecwarifachradcWegrdwudsentsubizoniSzprajenmrukto?.ale.lat.pan.wtedHopfpiwopan?uczoWtedbufeNatuWcalPoszegzaco..rezuprotakurbabarublrepupunkTurcanizbyc,magaZamomnozweksregumizelabochemIgnasam.kanaduzauleglustzgartylnbinonotaalbuStasneseCiekwazoKlejMrackupolalksredduzebrunkantkariDoprstycfoteteorLisisalogalgdymimorakalonumeAlezaleztlomdziugratprofinkaosmesnilfiglWydomechuscicyliPowoodciutoppisykwaronegZydkPalmEuropralnajokopemydlDomajejmtestpensco?.maz,CiotcerepoltpoufSkleszufkaftdyscprynsytufizjodznKatzupomlat,ziewmanefuntGrospasotutaparuLudwracjfaktMalg(nieprakBulgwakazajrfutrskomCha!cha!WybolutykufeDomy?...serikundA...LeckkupubodaowszgrudDopoCo?.drgnnic.no..PyszIzabkuzyFlorAleiUjazgabiMikoelekIstoograwycoKarocorclicyrewiAlejorygspecwizeinzyzjezakciwagosympzainpapodywaarystriuopinwytwusuwideai...dystBelclibeBaroMeliKrzenikcmeblJoasdol,szezBelupropsumynajtnerwzrujHortziryczybkoreplenzejdakceOtwoamattak?komba!..otozfryzszylopersufinie.Ach!ze..ten.naiwbezito..Komuzlap"DlakozlfrazcyfrbaloadreschakuflapatpchafatapradlokoWislZatrNowywejdzuzyuniwdyplSuzinosamikrmedykomoDoktblotSkietak.wydzkupnnie?Jerotam.metaMogedameNic.LadnkipisocjpazdPobibynadzenZiebraz."MozZbli"AhaDalsMariMachHeluskancyniAle.Oho!Aha!paltparwja..Pozedam,despPrezTrocUklosesjrok.Kazidni.bateaustbaluWegiklacwiormaniparohoryzadygroclzejAle,RokuparcObajJanoklapspryperkLaziStaceks-krymO!..teleapetHenrnihiNajwdyreHotepan!aleiNatyumizhotetechAdwoMaruOchodogoBodababy!...BeliBeladom.MisispazrejeobseZyd.YunglornanonKonsosioodegLiciomnilogigo..RossRomeOberwytoswinPifk"StaHum!arguSzpiuspaChinbabkfinaKasiLeonMageWirssystPatkbabcJumaSiuzmuzeuganGeisrasamedilufcEwelWasobrekFeliNiwiMalbSzasrautRzezMoli'
Znaki = {' ': (1, -3, 1), '.': (-96, -172, 268), ',': (9, 56, -66), '"': (-165, 213, -47), '?': (-104, -76, 181), '!': (-93, 122, -28), 'A': (4, 33, -37), 'a': (-20, 9, 11), 'b': (-6, 0, 7), 'c': (24, 2, -26), 'd': (-6, 11, -5), 'e': (4, -12, 7), 'f': (-49, -34, 84), 'g': (32, -16, -15), 'h': (23, 6, -30), 'i': (27, -18, -9), 'j': (24, -34, 9), 'k': (-53, 37, 15), 'l': (4, 0, -5), 'm': (12, -17, 4), 'n': (4, -19, 14), 'o': (8, -9, 0), 'p': (-6, -32, 38), 'q': (333, -111, -222), 'r': (0, 25, -26), 's': (6, 2, -8), 't': (2, -13, 10), 'u': (19, -16, -3), 'v': (301, -228, -72), 'w': (9, 18, -27), 'x': (333, -138, -194), 'y': (10, 8, -18), 'z': (11, 12, -23), 'B': (-120, 165, -45), 'C': (42, 22, -65), 'D': (-148, 228, -79), 'E': (252, -211, -41), 'F': (-108, -53, 161), 'G': (-8, 128, -120), 'H': (-210, 349, -138), 'I': (-179, 191, -11), 'J': (-125, 194, -68), 'K': (-141, 229, -88), 'L': (209, -43, -166), 'M': (-135, 99, 35), 'N': (-33, 57, -23), 'O': (-82, 119, -36), 'P': (-3, 77, -73), 'Q': (0, -333, 333), 'R': (-112, 206, -93), 'S': (-188, 198, -9), 'T': (-60, 166, -105), 'U': (35, 130, -165), 'V': (425, -259, -166), 'W': (-66, 19, 46), 'X': (-333, -333, 666), 'Y': (-333, -333, 666), 'Z': (-163, 234, -70)}

# pre.py 60 70 -> 83 punkty
# pre.py 30 50 + Znaki -> 90 punktów
# pre.py 30 50 + Znaki (wszystkie litery osobno) -> 90 punktów

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

    for c in book:
        #if ord(c) >= ord('A') and ord(c) <= ord('Z'): c = 'A'
        #if ord(c) >= ord('a') and ord(c) <= ord('z'): c = 'a'
        if c in Znaki:
            S, M, P = S + Znaki[c][0], M + Znaki[c][1], P + Znaki[c][2]
    
    if S > M and S > P: return 'Sienkiewicz'
    if M > S and M > P: return 'Mickiewicz'
    if P > S and P > M: return 'Prus'

    return 'Sienkiewicz'

t = int(input())
for _i in range(t):
    s = input()
    a = who(s)
    print(a)