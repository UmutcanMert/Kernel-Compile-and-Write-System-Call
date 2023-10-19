## Kernel Compile and Write System Call   

### Adım 1:
İlk adım olarak eğer bilgisarınızda linux kurulu değilse virtual box veya vmware indirip ardından sanal makine için bir linux sürümü indirmelisiniz.(Burada ubuntu için anlatacağım)  
Virtual box indirme linki:  
<br>
[https://www.virtualbox.org/wiki/Downloads](url)  
<br>  
Linux ubuntu indirme linki:  
[https://ubuntu.com/download/desktop](url)  
<br>
_______________
### Adım 2:  


Sıra ubuntu içinde kernel indirmeye geldi. Bunun için öncelikle terminalde ``` uname -r ```
komutunu çalıştırarak kernel sürümünüzü kontrol edin. Ardından [https://kernel.org/](url) sitesinden
sürümünüzle aynı veya en yakın kernel sürümünü tarball olarak indirin.

_______________
### Adım 3:  


İndirdiğiniz kernelin dizinine gidin ve tar şeklindeki kernel dosyasını şu komutla çıkarın:  
```tar xvf linux-6.0.7.tar.xz```

ardından ek paketleri indirin:  
```sudo apt-get install git fakeroot build-essential ncurses-dev xz-utils libssl-dev bc flex libelf-dev bison ```
