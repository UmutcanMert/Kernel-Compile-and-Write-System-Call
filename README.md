## Kernel Compile and Write System Call   

### Adım 1:
İlk adım olarak eğer bilgisarınızda linux kurulu değilse virtual box veya vmware indirip ardından sanal makine için bir linux sürümü indirmelisiniz.(Burada ubuntu için anlatacağım)  
Virtual box indirme linki:  
<a href="https://www.virtualbox.org/wiki/Downloads" target="_blank">VirtualBox</a>  
<br>

Linux ubuntu indirme linki:  
<a href="https://ubuntu.com/download/desktop" target="_blank">Ubuntu</a>  
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
<a href="https://kernel.org/" target="_blank">Kernel install</a>  
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


İndirilen kernel dosyasında şu dosyayı açın:
```
nano arch/x86/entry/syscalls/syscall_64.tbl
```

Bu dosya system call ekleyeceğimiz dosyadır. O yüzden bu dosyada 300lü system callların sonuna bir sonraki numara ile kendi system callunuzu
ekleyin. Sıradaki numara 335 ise:
<p> 
  <strong>(Aralarda tab kadar boşluk vardır) 
  </strong>
</p>  


```
335  common  kendiisminiz      sys_kendiisminiz
```


<br>
Eğer sisteminiz 64 bit ise tablonun en sonuna da yazabilirsiniz system callu. Tabi o zaman 335 numarası değişecek.  


_______________
### Adım 8:  
Bu adımda kernel dosyasında kernel/sys.c dosyasını açarak en sonuna şu kodu eklemelisiniz: (Kendi system callunuza göre kodu düzeltin)
```
SYSCALL_DEFINE1(kendiisminiz, char *, msg)
{
  char buf[256];
  long copied = strncpy_from_user(buf, msg, sizeof(buf));
  if (copied < 0 || copied == sizeof(buf))
    return -EFAULT;
  printk(KERN_INFO "kendiisminiz syscall called with \"%.256s\"\n", buf);
  return 0;
}
```

**Bu fonksiyonun herhangi bir if vb macro bloğunun içinde olmamasına dikkat edin.**



_______________
### Adım 9:
KERNEL COMPİLE VE İNSTALL
Öncelikle indirilen kernel dosyasının başlangıç dizinine geliniz. Yani şöyle bir dizinde olduğunuzdan emin olduktan sonra:
<br>
```    linux-VERSION$    ```
<br>
<img src="deploy.sh" alt="Mountain">
bir deploy.sh dosyası oluşturun ve dosyaya şunları yazın:



