# ================================
# Serveur UDP - Écoute sur port 1234
# ================================

$port = 1234

# Création du serveur UDP
$udpClient = New-Object System.Net.Sockets.UdpClient($port)

Write-Host "✅ Serveur UDP en écoute sur le port $port..."
Write-Host "En attente de messages..."


# Boucle infinie
while ($true) {

    # Préparation de l'adresse distante (client)
    $remoteEndPoint = New-Object System.Net.IPEndPoint([System.Net.IPAddress]::Any, 0)

    # Réception des données
    $data = $udpClient.Receive([ref]$remoteEndPoint)

    # Conversion en texte
    $message = [System.Text.Encoding]::UTF8.GetString($data)

    # Affichage
    Write-Host "-----------------------------------"
    Write-Host "📩 Message reçu !"
    Write-Host "📌 Depuis : $remoteEndPoint"
    Write-Host "💬 Contenu : $message"
    Write-Host "-----------------------------------"
}
