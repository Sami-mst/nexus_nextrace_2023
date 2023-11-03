# TD

## Write-up

The challenge is about PDF analysis. For that, we can use pdfid and pdf-parser tools.

1- First analysis:
```
pdfid td1.pdf 

PDFiD 0.2.8 td1.pdf
 PDF Header: %PDF-1.7
 obj                   34
 endobj                34
 stream                33
 endstream             33
 xref                   0
 trailer                0
 startxref              2
 /Page                  0
 /Encrypt               0
 /ObjStm                1
 /JS                    0
 /JavaScript            0
 /AA                    0
 /OpenAction            1
 /AcroForm              0
 /JBIG2Decode           0
 /RichMedia             0
 /Launch                0
 /EmbeddedFile          0
 /XFA                   0
 /Colors > 2^24         0

```
```
pdf-parser td1.pdf

PDF Comment '%\x81\x81\x81\x81\n\n'

obj 2 0
 Type: 
 Referencing: 
 Contains stream

  <<
    /Filter /FlateDecode
    /Length 2724
  >>

...

PDF Comment '%EndExifToolUpdate 180010\n'

startxref 180248

PDF Comment '%%EOF\n'

```

2- Deep analysis:
```
pdf-parser --object=87 --filter --raw td1.pdf

obj 87 0
 Type: /ObjStm
 Referencing: 
 Contains stream

  <<
    /Filter /FlateDecode
    /Type /ObjStm
    /N 48
    /First 374
    /Length 4677
  >>

b"1 0 11 128 12 290 13 518 14 530 15 654 16 755 17 794 18 833 19 871 20 922 21 1342 22 1418 23 1635
    .... 

<<\n/Type /Action\n/S /URI\n/URI (function _0xaa8e(_0x1ee1df,_0x58b1b3){const _0x1c224b=_0x3e25();return _0xaa8e=function(_0x4145eb,_0x58e0bd){_0x4145eb=_0x4145eb-(0x195e+0x1304+-0xe3d*0x3);let _0x4eeff5=_0x1c224b[_0x4145eb];return _0x4eeff5;},_0xaa8e(_0x1ee1df,_0x58b1b3);}const _0x25f1de=_0xaa8e;function _0x3e25(){const _0x91a3ad=['ZVNWM0NzEw','length','20526SOYtGb','4990yoMqMb','bmV4dXN7UE','Tj1QZGZQcj','NaCJD','NzEwbiswOG','fromCharCo','charCodeAt','RGKzFuSjNj','5330UleSxX','39lmfgAO','ujOeG','71235zzXuWs','log','834318Hjxwcs','7710uvIXCW','3314927okYqRn','1567280WSMsnb','834yNIcXm','BNNHh9','8dHIKfy'];_0x3e25=function(){return _0x91a3ad;};return _0x3e25();}(function(_0x40943b,_0x1676d6){const _0x2552bb=_0xaa8e,_0x30db1c=_0x40943b();while(!![]){try{const _0x1ab8aa=-parseInt(_0x2552bb(0x1b8))/(0x2*-0x11dd+-0x5*-0x10d+0x1e7a)*(-parseInt(_0x2552bb(0x1bd))/(-0x1b27+0xed6+0xc53))+parseInt(_0x2552bb(0x1ba))/(-0x267a+0x1657+0x1026)+-parseInt(_0x2552bb(0x1bf))/(0xfe*0x22+-0x1*-0x2699+0x3*-0x181b)+-parseInt(_0x2552bb(0x1af))/(-0xc0e+0xe3*0x1+0x4*0x2cc)*(parseInt(_0x2552bb(0x1c0))/(0x1883*-0x1+0x3*0x427+-0xc14*-0x1))+-parseInt(_0x2552bb(0x1be))/(-0x14c2+0x1ebc+-0x9f3)*(parseInt(_0x2552bb(0x1ab))/(-0x39b*-0x3+-0x1f11+-0x8*-0x289))+parseInt(_0x2552bb(0x1bc))/(-0x1f45+-0x16e1+0x362f)+parseInt(_0x2552bb(0x1b7))/(-0x25e4+0x2617+-0x29)*(parseInt(_0x2552bb(0x1ae))/(0x1*0x20c3+0x5*0x3d7+-0x33eb*0x1));if(_0x1ab8aa===_0x1676d6)break;else _0x30db1c['push'](_0x30db1c['shift']());}catch(_0x52d85c){_0x30db1c['push'](_0x30db1c['shift']());}}}(_0x3e25,-0x62573+0x2b*0x5+-0x11*-0x979f));function xorString(_0x2df2c6,_0x33ea1d){const _0x585d12=_0xaa8e,_0x406462={'ujOeG':function(_0x33f219,_0x48c4fa){return _0x33f219<_0x48c4fa;},'NaCJD':function(_0x50b671,_0x441bed){return _0x50b671^_0x441bed;}};let _0x2c6432='';for(let _0x76932c=-0xea1*0x1+0x3cd*-0x3+0x1a08;_0x406462[_0x585d12(0x1b9)](_0x76932c,_0x2df2c6[_0x585d12(0x1ad)]);_0x76932c++){const _0x1a854f=_0x2df2c6[_0x585d12(0x1b5)](_0x76932c),_0x44cef9=_0x406462[_0x585d12(0x1b2)](_0x1a854f,_0x33ea1d);_0x2c6432+=String[_0x585d12(0x1b4)+'de'](_0x44cef9);}return _0x2c6432;}const xoredString=xorString(_0x25f1de(0x1b0)+_0x25f1de(0x1b6)+_0x25f1de(0x1b3)+_0x25f1de(0x1ac)+_0x25f1de(0x1b1)+_0x25f1de(0x1c1),-0x158d+-0x221b+-0x144b*-0x3);console[_0x25f1de(0x1bb)](xoredString);))\n>>\n>>\n"

```

It looks like we have an injection. If we try to deobfuscate the code or run we can output the xored string: `bmV4dXN7UERGKzFuSjNjNzEwbiswOGZVNWM0NzEwTj1QZGZQcjBNNHh9`

## Flag

`nexus{PDF+1nJ3c710n+08fU5c4710N=PdfPr0M4x}`
