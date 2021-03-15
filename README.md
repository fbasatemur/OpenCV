# OpenCV (C++)

## OpenCV Kurulumu ve Visual Studio Entegresi

### OPENCV KURULUMU :
Öncelikle OpenCV kütüphanesini makinemize indiriyor ve istediğimiz bir dizine çıkarıyoruz. 

http://opencv.org/releases.html adresinden istenilen version (bendeki 4.1.1) indirilebilir. Kütüphane dosyasını istediğimiz herhangi bir dizinde çıkarabiliriz. Ben C:\ dizinini tercih ettim.

Kütüphaneyi rahatça kullanabilmek için gerekli pathlerin verilmesi gerekiyor, sırasıyla;

**Control Center -> System and Security -> System -> Advanced System Settings** yolunu izliyoruz. Daha sonra "Environment Variables" butonuna tıklıyoruz. Açılan ekranda aşağıda gösterilen Path yazan yere tıklayıp, düzenle butonuna basıyoruz.

Ben C:\ dizinine OpenCV kütüphanesini çıkarttığım için C:\opencv\build\x64\vc14\bin adresini yeni butonuna bastıktan sonra yapıştırıyoruz. Bu adres sizde OpenCV ‘yi çıkarttığınız yere göre değişkenlik gösterebilir.


### OPENCV VISUAL STUDIO 2018 ENTEGRESİ:

Daha sonra uygulamayı C++ ile Visual Studio ortamında yazacağımızdan dolayı Visual C++ Win32  Konsol Uygulaması oluşturuyoruz. 

**ÖNEMLİ:** Eğer VStudio toolbar da Debug seçeneği x86 ise onu x64 yapıyoruz. Bu işlemin sebebi OpenCV'nin v3.0 ile birlikte yalnızca x64 mimariyi desteklemesidir. Ayrıca **debug** mode yerine **release** mode çalışmak isteyebilirsin. Bunun için yapman gereken yalnızca son adımda kullanılan **opencv_world411d.lib** ismindeki **-d** harfini silmektir, bu debug anlamına gelir.


Derleyicinin sağ üst bölümünde bulunan **Solution Explorer -> Properties** diyoruz.

Sizin kurduğunuz dizine göre değiştirip opencv\build\include dizinini;

**Configuration Properties -> VC++ Directories -> Additional Include Directories** kısmına yapıştırın. Ben ekleme kodu dosyalarını C’ye çıkardığımdan, *C:\opencv\build\include* adresinini yapıştırıyorum.

Yine sizin kurduğunuz dizine gore degistirip opencv\build\x64\vc14\lib dizinini;

**Configuration Properties -> VC++ Directories -> Library Directories** kısmına yapıştırın. Ben kütüphane dosyalarını C'ye çıkardığımdan, C:\opencv\build\x64\vc14\lib adresini ekliyorum.

Son olarak kurduğunuz sürüme göre faklılık oluşturan **opencv_world411d.lib** dosya ismini:

VC++ Dizinleri deki işlemlerimizi hallettikten sonra **Configuration Properties -> Linker -> Input -> Additional Dependincies** seçeneğine tıklıyoruz. *C:\opencv\build\x64\vc14\lib* dizininde bulunan, **opencv_world411d.lib** dosyasını (debug mode için) ekliyoruz.

Bu işlemlerden sonra örnek proje kodları çalıştırılabilir.



