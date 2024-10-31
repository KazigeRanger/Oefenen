#include <string>
#include <iostream>
using namespace std;

class Song {
    private:
        string _title;
        string _album;
        string _artist;
        string _genre;
        int _lengthMinutes;
        int _lengthSeconds;

    public:
        // Define constructor
        Song(string title, string album, string artist, string genre, int lengthMinutes, int lengthSeconds) 
            : _title(title), _album(album), _artist(artist), _genre(genre), _lengthMinutes(lengthMinutes), _lengthSeconds(lengthSeconds) {}

        // Define getter functions
        string getTitle() {
            return _title;
        }
        string getAlbum() {
            return _album;
        }
        string getArtist() {
            return _artist;
        }
        string getGenre() {
            return _genre;
        }
        int getLengthMinutes() {
            return _lengthMinutes;
        }
        int getLengthSeconds() {
            return _lengthSeconds;
        }

        // Define setter functions
        void setTitle(string title) {
            _title = title;
        }
        void setAlbum(string album) {
            _album = album;
        }
        void setArtist(string artist) {
            _artist = artist;
        }
        void setGenre(string genre) {
            _genre = genre;
        }
        void setLengthMinutes(int lengthMinutes) {
            _lengthMinutes = lengthMinutes;
        }
        void setLengthSeconds(int lengthSeconds) {
            _lengthSeconds = lengthSeconds;
        }

        // Define destructor
        ~Song() {
            cout << "Song removed";
        }
};

int main() {
    Song song("Ma quale idea", "Italian Classics Vol.1", "Pino D'Angio", "Italian", 4, 22);

    return 0;
}