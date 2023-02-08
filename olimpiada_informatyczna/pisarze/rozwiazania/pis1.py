#!/usr/bin/python3

#  Jan Zakrzewski
#  XXVII Olimpiada Informatyczna, Etap II
#  Zadanie `Pisarze (pis)'

Sienkiewicz = 'PetrNeroOthoarbilaznretoinsuWatyLukaSeneoliwgemmAlbaMarkWiniAzjiwpussyneTybeKorbPartukonatleestePozdbogoRzymBityHeraPoppbarbPorthypotuniPalaHerkmozaZeusbiblAgryWschCezaupewTrazRufiniszfaunust,lutnTedydeklunctmascgietvesttoganozdAuluPlauPompLigiKallLigoAfroodkuHistWannSweblupiHermKlaulupaGermGrectchnSoraFeniEgipindzAulaAferTygeAhentricsil,Heli"bosAlektogiEunijenotejzuniopranrzymJowiForuatrivelacubiwerwVicuOlbrlektwillwigiBrytItalLicytrzcirystarcAtenWenutogerybeNeapwydlplytKastPollfletWsrowzbinaokKwirGaloznadGrekwyspGaliSerapalmznosbilinocezatykrypSubuSekulud,OktascepzbrzWiteflamChreKrysimpltablWespzylyorazpilkZyciblusAntyKalwamfiBogoSaturzutBlogHomealabodblbezdmirtAnakzalicytromdlzdacJaniZaliLibiKampcos,ukojzyliKornDianmiluAkteFortTeokNiegumocNazamisedrapKajuHastBoskzal,lkanlaraAppiTak!zmilpeplUrsuorszCyprPawlTarsgorlBiadnalobezszmagTerpmedrkranobelpoturozhpomsnamotwympchnMilusestUczyligiabysbezkusprcnoczlymergaCzynspasolsnmekewam,ufnocudasen,podtzwilnumiupiepolbKalijekismaghelmmigozrosobnamirrupajupojgdysolimTulibiodRubrbykaNigiAncjmorshymnulgiSabiobalDiodPitakagauroksyryswitratodressil.orgiwyziZaniBaiazmroLigabiecpiniZolnBozaBaraJemubiskLinubezeKaryAfryudacwezbPomoAtacwelnalekuzysHadezaulkijatlokaugudeptKrewmulyigrzzlycsnu.tchugaliTejrutwiChilszopsynuroilSenalud.Demazbralzy,igraJuniZbawGlauMerkjaloTybrtratEuryOstiarcycariCumaAchaAmfiBeneAlitsektJudejawnObecPriaucznJakkZrozZatyKwarEmpoAwenCyrkJudazewnUrbaukrzodpumekiAposSalaNomezaswdojsOzyredykbog,tesspoobDrogwawofossmurehen,zsta"ChrdechzwatSynaowceMamedomkTobizburMirimdleLitolodzbluzpascArycPretPromharfOgieostoTroiOlimPizoNerwEskwosiavivalwowlwy,FaonUstrPozadymodymyCaelzgligineFlawJehomulaTullcuniChripodiKaleLaniCuchDoloCoriNigeScew'
Mickiewicz = 'OjczBramludelonoSzergrykgrusbrzozewsstodgrzabrykganePodrKoncOglazdalczamPolsmocapadnRejtwnisalkoDabrmazuPeteochmnutyziolPolyBialWysmpuklwezewionwleczmrusianWojsWdzi"DobTadeStrysadyPodkzniwGospkragSpusboruNapewiazBlyssuwamawiEkonzytaCieswolyWesodozwpyluStadlecalakibiezutrugronNajloborWoznProtzamcizbaOknaHoregotyarchtem,WilnZmierefefilaSciasarnjelePolkbernBernzmowwodkwtenzwawjedlPustJakbRoztnadoDanoRozyogorRzekwegr"DziwnukWojemoscGrzemodnDawapuchWtenZwlaafekZnacmowytabamodaraptGadanosyOdbiKrzyswawchmirunaambochluWyjegaweorezwawrRoba"MniRykokwatRuskarmiGladdruzMajoPlutSuwalisapazuObacGorskregPosrwarklawyKrecpekilowyAsesRejeklotSokoKusetajnkruczwijnazbkraslicawzbrNazySoplflinszabbebnIlekleklGorzWszcSasiKogogalkwsieZwanwytksmyc"WyckurkdwursmykzagoKusySzaruche"Prasejmzadlwydrstrwpsia"ChaTelilowakich"WiwTabaknieodwozazyecheLachwojemniclowiDzikklowZadelowoTrafPuszHrecKrajRozbBrzelitykutamychdobyOginRymsGiedwywasad,zupa"UcilzacorlySlawRosySpadRodzrodaKniakedyskaknurkKsieMiercarszgonRozezestmszamszywydekarcbujadareOwdzwrobjastwojuwkramigapregklosskacgasiechoOdezrykipaserumacwalRuszCwalzlacPojeobydopokPedzUkazWiezsterblacZwalRomakon,GerwWkolPowtMopaRebaKlucUwiaChylkordSklografStolmopamaru"ZgoZsiazsiawnoswiwaKrolprymWiwaPogllowcJaceSzabOwozWasazieczagnKuchhajdtaralamuObroslanWzniruryzboj"MoswrotodsirapiScyzDwocpisktykakopcmeznNowazoczplocDrzekapuTam,kukulodykonozmijowadbadyliceplywSlomRekadzioczatnodzWascmignpszcRoznimbrfiliwicitrunmiodkabaWyrzcaraGodnKiryKozoStajRozsudobkozymarimospResznawzWstrustypajebzykzbadtylateginatrSzmeZdzilajazwadkapowslaostenizllasasuszsalaSangpyskswarWzieagrezleklopuWytkWymylacnkurypawiOdkrwiankoraNibyWisikitkDziaglasjagomodrpelzherolosoWycitonyZagaponoslomuwiakoneblawStapspicTamcgolaoponpioslikuOddagescChow*SwiZimnpstrDarmSchy"WidasckdociZlozWartzimyordeunizfraslosiZosiwacpJackZrazMalaIdziPonoostypanyUdajDobyNabrpejz"BrarysuuragLiteCzerUbraStoitopodebodasazzympalkkunsOrloilezulewChmuScisWysuCichRachryknniknPapizwinPorwDzwoOdglPelnobadskoksiwaDwiePiesrusktasa"StrPonaLezaWilezubrkolpJagimonasieklipaklodwymkszystanepniaZgadZnikhaslrubiwznaSkocWyskopetKedyKoraTrwaJankMuzyZawiSkolczubrodeKorosyzmWilbSkar"Oj,odarwascbakiPodhBirbGdanCesaBrzyPrusrdzakotlZajaWpadrazoUciechytzgratroppsiezmykChcaRyknlomuRwalzbilNatecetkwplawbitPijaruraSaga"TerDomeDowerureOdwacyngPodschruBuchflasbigoBierkwasprysZbroWstywyreWznonim;pjan"DosmetyZgodZbladygnsitorosoLeci"SedizbeObraPowsTrzaDaredarnkurchaniOdmicoryuchuoba,natarejtDenaNadabozyraneOzwaDotaPorzWskamaryciacZawoUrodOkrecwiedekrCofaSledskubTargMacizascwijaBydlbociwronslotSkrzguzyObmyBrachodobabiWojnwoziZalaPogopisnBiezoba.WidnszteBartMackgumnsero*RozmacaBronbojuWiatWynioczkGestTen,Grabszef"JenKlanHejzzwleKropSejm"KroKone"PredraghejzKlecwyucplusRozgaktasaznSzyd"Hejlisizatkjegrphu,SakazagicietZlak"ZdrrotaNikiszpo"MajSybicha,dukahulaSierJegrkosaGifrZebrfechRazePropdzidciecWalcRecepardroteRyceMazuserndrwaKrwicarenawabonoZofiBrzmPanedbamTeczpychImietyzeLaskzuraulanZdobomenzimedygaOfickupkJeneakor'
Prus = 'kupcKrakfirmMincWokufabrcygageniBismawankrytzdecwarifachradcWegrdwudsentsubizoniSzprajenmrukto?.ale.lat.pan.wtedHopfpiwopan?uczoWtedbufeNatuWcalPoszegzaco..rezuprotakurbabarublrepupunkTurcanizbyc,magaZamomnozweksregumizelabochemIgnasam.kanaduzauleglustzgartylnbinonotaalbuStasneseCiekwazoKlejMrackupolalksredduzebrunkantkariDoprstycfoteteorLisisalogalgdymimorakalonumeAlezaleztlomdziugratprofinkaosmesnilfiglWydomechuscicyliPowoodciutoppisykwaronegZydkPalmEuropralnajokopemydlDomajejmtestpensco?.maz,CiotcerepoltpoufSkleszufkaftdyscprynsytufizjodznKatzupomlat,ziewmanefuntGrospasotutaparuLudwracjfaktMalg(nieprakBulgwakazajrfutrskomCha!cha!WybolutykufeDomy?...serikundA...LeckkupubodaowszgrudDopoCo?.drgnnic.no..PyszIzabkuzyFlorAleiUjazgabiMikoelekIstoograwycoKarocorclicyrewiAlejorygspecwizeinzyzjezakciwagosympzainpapodywaarystriuopinwytwusuwideai...dystBelclibeBaroMeliKrzenikcmeblJoasdol,szezBelupropsumynajtnerwzrujHortziryczybkoreplenzejdakceOtwoamattak?komba!..otozfryzszylopersufinie.Ach!ze..ten.naiwbezito..Komuzlap"DlakozlfrazcyfrbaloadreschakuflapatpchafatapradlokoWislZatrNowywejdzuzyuniwdyplSuzinosamikrmedykomoDoktblotSkietak.wydzkupnnie?Jerotam.metaMogedameNic.LadnkipisocjpazdPobibynadzenZiebraz."MozZbli"AhaDalsMariMachHeluskancyniAle.Oho!Aha!paltparwja..Pozedam,despPrezTrocUklosesjrok.Kazidni.bateaustbaluWegiklacwiormaniparohoryzadygroclzejAle,RokuparcObajJanoklapspryperkLaziStaceks-krymO!..teleapetHenrnihiNajwdyreHotepan!aleiNatyumizhotetechAdwoMaruOchodogoBodababy!...BeliBeladom.MisispazrejeobseZyd.YunglornanonKonsosioodegLiciomnilogigo..RossRomeOberwytoswinPifk"StaHum!arguSzpiuspaChinbabkfinaKasiLeonMageWirssystPatkbabcJumaSiuzmuzeuganGeisrasamedilufcEwelWasobrekFeliNiwiMalbSzasrautRzezMoli'
Znaki = {' ': (1, -3, 1), '.': (-96, -172, 268), ',': (9, 56, -66), '"': (-165, 213, -47), '?': (-104, -76, 181), '!': (-93, 122, -28), 'A': (-69, 116, -47), 'a': (5, -1, -3)}

# pre.py 60 70 -> 83 punkty
# pre.py 30 50 + Znaki -> 90 punktów
# pre.py 30 50 + Znaki (wszystkie litery osobno) -> 90 punktów
# pre.py 60 70 1000 150

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
        if ord(c) >= ord('A') and ord(c) <= ord('Z'): c = 'A'
        if ord(c) >= ord('a') and ord(c) <= ord('z'): c = 'a'
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