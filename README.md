<h1>Choco Alt Install</h1>
A simple alternative to chocolatey's "install packages.config"<br>
It works just by providing the file with the packages names. example file: <code>apps.txt</code><br>
Actually, i've developed this because i didn't know the existence of this command.

<h2>Usage</h2>
<p>To use it, first, compile, then run (on powershell):</p>
<pre><code>Get-Content YourApps.txt | choco-install.exe</code></pre>
