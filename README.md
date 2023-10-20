## Kernel Compile and Write System Call   

### Adım 1:
İlk adım olarak eğer bilgisarınızda linux kurulu değilse virtual box veya vmware indirip ardından sanal makine için bir linux sürümü indirmelisiniz.(Burada ubuntu için anlatacağım)  
Virtual box indirme linki:  
[https://www.virtualbox.org/wiki/Downloads](url)  
<br>  
Linux ubuntu indirme linki:  
[https://ubuntu.com/download/desktop](url)  
<br>
_______________
### Adım 2:  


Sıra ubuntu içinde kernel indirmeye geldi.
<br>  
Bunun için öncelikle terminalde
<br>
```      
uname -r
```
<br>
komutunu çalıştırarak kernel sürümünüzü kontrol edin.
<br>
Ardından:
<br>
[https://kernel.org/](url)
<br>
sitesinden sürümünüzle aynı veya en yakın kernel sürümünü tarball olarak indirin.

_______________
### Adım 3:  


İndirdiğiniz kernelin dizinine gidin ve tar şeklindeki kernel dosyasını şu komutla çıkarın:  
```
tar xvf linux-6.0.7.tar.xz
```   
**(burada 6.0.7 yerine sizin indirdiğiniz versiyon olacak)**  


ardından ek paketleri indirin:  
```
sudo apt-get install git fakeroot build-essential ncurses-dev xz-utils libssl-dev bc flex libelf-dev bison
```  
**bu compile derlenirken minimum hata almanıza yardımcı olacak**

_______________
### Adım 4:  


Tardan çıkardığınız kernel dosyasına girin:    
<br>
```
cd linux-Version
```  
<br>
<br>
Ardından sizin mevcut kerneldaki config dosyasınızı tardan çıkardığınız kernel dosyasına kopyalamanız gerekiyor. Bunun içinde:
<br>
```
cp -v /boot/config-$(uname -r) .config
```  
<br>
komutunu giriniz.  
**Bu kısımda ubuntu kullanıyorsanız bu komut geçerli. Başka bir linux sisteminde komut değişir.**


_______________
### Adım 5:  


Sonrasında şu komutu çalıştırın:
<br>
```
yes "" | make oldconfig
```
_______________
### Adım 6:  


Oluşturulan config dosyasına girerek **CONFIG_LOCALVERSION=""** kısmını editlemeniz gerekir. Bunun için terminalden:
<br>
```
nano .config
``` 
<br>
komutu çalıştırarak girebilirsiniz. Ardından eğer editleyeceğiniz kısmı göremediyseniz **Control + W** ile search edip bulabilirsiniz.
(büyük küçük harf ve türkçe harf kullanımına dikkat ediniz)
<br>
**CONFIG_LOCALVERSION="-kendiisminiz"** şeklinde değiştirin.
_______________
### Adım 7:  
_______________
### Adım 8:  



