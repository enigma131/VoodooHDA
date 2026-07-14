VoodooHDA 32 bits
=================

I had no audio from Tiger to Lion on the Acer laptop hackintosh, so the idea for this project comes.  
First commit is without prefpane because, as you know, this can't be made with Xcode 2.5 tools.  

Start point : Forked from https://github.com/CloverHackyColor/VoodooHDA project release 3.1.2  
Thanks to developers (slice, chris1111 and original developers)   
Some parts of code adapation comes from svn archives, example to get release 77  
svn checkout -r 77 https://svn.code.sf.net/p/voodoohda/code/ voodoohda-code-r77  

### Commit 1 :  
Xcode 2.5 compatibility, targets Tiger + Leopard 32 bits, compiled kext embedded in build folder  
Reworked kernel/darwin 8 adaptations and log system for compatibility.  
Be careful: Compilation with TIGER flag, see in project settings.    
VoodooHDA.xcodeproj is located in tranc folder like original project.  
If you need a FAT version, you can combine Tiger 32 bits compilation and Snow Leopard 64 bit compilation (Xcode 4.6 is need) with lipo  

Using with Opencore:  
Kernel->block : com.apple.driver.AppleHDA  
Kernel->force : com.apple.iokit.IOAudioFamily, /System/Library/Extensions/IOAudioFamily.kext, max kernel 9.9  
Kernel->force : com.apple.kext.OSvKernDSPLib , /System/Library/Extensions/OSvKernDSPLib.kext, max kernel 9.9  
Kernel->add   : your compiled VoodooHDA.kext (32 bits or FAT version)  
  
### Commit 2 :  
Add my audio device identification (Alc283)  
  
  
Original readme.md :  

### Compilation.
If you are using systems up to Catalina then open project 
tranc/VoodooHDA.xcodeproj

For systems BigSur and up you have to download the project VoodooHDA
also download MacKernelSDK
~~~~
git clone https://github.com/joevt/MacKernelSDK.git
~~~~

(this is tested version)
and make a symlink into project
~~~~
cd /path_to/VoodooHDA/
ln -s /path_to/MacKernelSDK MacKernelSDK
~~~~

open project
tranc/VoodooHDA_BS.xcodeproj
and compile

download VoodooHDA.prefPane
1. go to the Release302 of my Release
2. download VoodooHDA.prefPane.zip
3. after downloading, extract it

### Installation

1. Exclude other Audio kexts
2. Set SIP disable kext or just 
~~~~
sudo nvram csr-active-config=0xA85
~~~~

3. Reboot
4.
~~~~
sudo cp -R /path_to/VoodooHDA.kext /Library/Extensions/
sudo cp -R /path_to/VoodooHDA.prefPane /Library/PreferencePanes/
~~~~

5. Wait while the system saids that the kext must be approved
6. Go to System Settings and approve the kext.
7. Reboot.
8. Enjoy your favorite music.

### Fix for Mic is showing but not getting any input (AMD/Intel)

1. Go to the System Settings>VoodooHDA.
2. Then select your microphone.
3. Set the **IMix** & **Speaker** slider to maximum.
Mic should work.
