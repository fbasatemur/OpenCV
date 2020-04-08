# OpenCV (C++)

## OpenCV Kurulumu ve Visual Studio Entegresi

### OPENCV KURULUMU :
Öncelikle OpenCV kütüphanemizi makinemize indiriyor ve istediğimiz bir dizine çıkarıyoruz. 

http://opencv.org/releases.html adresinden istenilen version (bendeki 4.1.1) indirilebilir. Kütüphane dosyasını istediğimiz herhangi bir dizinde çıkarabiliriz. Ben C:\ dizinini tercih ettim.

Kütüphaneyi kullanabilmek için “Path” işlemini yapmamız gerekiyor. “Path” işlemini yapmak için sırasıyla;

**Denetim Masası\Sistem ve Güvenlik\Sistem** yolunu izliyoruz. Daha sonra “Gelişmiş sistem ayarları” dizinine giriyoruz. Daha sonra ortam değişkenleri butonuna tıklıyoruz. Açılan ekranda aşağıda gösterilen Path yazan yere tıklayıp, düzenle butonuna basıyoruz.

Ben C:\ dizinine OpenCV kütüphanesini çıkarttığım için C:\opencv\build\x64\vc14\bin adresini yeni butonuna bastıktan sonra yapıştırıyoruz. Bu adres sizde OpenCV ‘yi çıkarttığınız yere göre değişkenlik gösterebilir. Buradaki asıl amaç adresin sonundaki bin dizinine erişmek. Bu işlemi yaptıktan sonra tamam butonuna basarak bütün pencereleri kapatın. “Path” işlemini başarıyla tamamladık.


### OPENCV VİSUAL STUDİO 2018 ENTEGRESİ:

Daha sonra uygulamayı C++ ile Visual Studio ortamında yazacağımızdan dolayı Visual C++ Win32  Konsol Uygulaması oluşturuyoruz. 

Kaynak dosyalarına sağ tıklayıp ekle -> yeni öğe dedikten sonra C++ kaynak dosyasını sağ altta ekle butonuna basarak oluşturuyoruz.

**ÖNEMLİ:** Bu işlemleri yaptıktan sonra eğer derleyicimizin yukarısında Debug seçeneği x86 ise onu x64 yapıyoruz.



Derleyicinin sağ üst bölümünde bulunan Çözüm Gezgininden (Solution Explorer), Projenin ustune gelip sağ tıklayıp özellikler diyoruz.


Sizin kurduğunuz dizine göre değiştirp opencv\build\include dizinini;

**Yapılandırma Özellikleri -> VC++ Dizinleri -> Ekleme Kodu Dizinleri** kısmına yapıştırın. Ben ekleme kodu dosyalarını C’ye çıkardığımdan, *C:\opencv\build\include* adresinini Ekleme Kodu Dizinlerine yapıştırıyorum.


Yine sizin kurduğunuz dizine gore degistirip opencv\build\x64\vc14\lib dizinini;

**Yapılandırma Özellikleri -> VC++ Dizinleri -> Kitaplik Dizinleri** kısmına yapıştırın. Ben kütüphane dosyalarını C'ye çıkardığımdan, C:\opencv\build\x64\vc14\lib adresini eklemiş oluyorum.


VC++ Dizinleri deki işlemlerimizi hallettikten sonra **Yapılandırma Özellikleri -> Bağlayıcı -> Giriş -> Ek Bağımlılıklar** seçeneğine tıklıyoruz. *C:\opencv\build\x64\vc14\lib* dizininde bulunan, **opencv_world320d.lib** dosyasını ekliyoruz ve pencereleri uygula diyerek kapatıyoruz.

Bu işlemlerden sonra örnek proje kodları çalıştırılabilir.

