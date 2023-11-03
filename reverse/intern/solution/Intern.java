import java.io.*;
import java.nio.file.Files;
import java.security.*;

public class Intern {

    public static void main(String[] args) throws IOException,NoSuchAlgorithmException {
        String inputFile = "flag.png";
        String key = "R34lly_secret_key";

            encryptImage(inputFile, key);

    }

    private static void encryptImage(String inputFile, String key) throws IOException, NoSuchAlgorithmException {
        byte[] keyBytes = key.getBytes("UTF-8");
        MessageDigest digest = MessageDigest.getInstance("SHA-256");
        byte[] hashedKeyBytes = digest.digest(keyBytes);

        byte[] inputBytes = Files.readAllBytes(new File(inputFile).toPath());
        byte[] encryptedBytes = new byte[inputBytes.length];
        for (int i = 0; i < inputBytes.length; i++) {
            encryptedBytes[i] = (byte) (inputBytes[i] ^ hashedKeyBytes[i % hashedKeyBytes.length]);
        }


        saveEncryptedImage(encryptedBytes, "encrypted_flag.png");
    }

    private static void saveEncryptedImage(byte[] encryptedBytes, String outputFile) throws IOException {
        try (FileOutputStream outputStream = new FileOutputStream(outputFile)) {
            outputStream.write(encryptedBytes);
        }
    }

    private static void decryptImage(String inputFile, String key) throws NoSuchAlgorithmException,UnsupportedEncodingException,IOException {
        byte[] keyBytes = key.getBytes("UTF-8");
        MessageDigest digest = MessageDigest.getInstance("SHA-256");
        byte[] hashedKeyBytes = digest.digest(keyBytes);
        byte[] encryptedBytes = Files.readAllBytes(new File(inputFile).toPath());


        byte[] decryptedBytes = new byte[encryptedBytes.length];
        for (int i = 0; i < encryptedBytes.length; i++) {
            decryptedBytes[i] = (byte) (encryptedBytes[i] ^ hashedKeyBytes[i % hashedKeyBytes.length]);
        }

        try (FileOutputStream outputStream = new FileOutputStream("decrypted_flag.png")) {
            outputStream.write(decryptedBytes);
        }
 

    }

}

