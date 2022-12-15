const express = require('express'); // Import the express library
const fs = require('fs'); // Import the fs (file system) module
const app = express(); // Create an instance of express

const PATH_TO_DATA = '/home/pranay/Documents/DSTN/assignments/final_proj/dstn-geofen-storage/data';
const PATH_TO_COMPRESSED = '/home/pranay/Documents/DSTN/assignments/final_proj/dstn-geofen-storage/compressed';

app.get('/getlatest', (req, res) => {
    console.log("got a request for /data");
    fs.readdir(PATH_TO_DATA, (err, files) => {
        if (err) {
            console.log(err)
            res.status(500).send({ error: 'Error reading data directory' });
        } else {
            res.type('text/csv');
            const latestFile = files.sort().pop(); // Get the latest file
            res.sendFile(PATH_TO_DATA +'/' + latestFile);
        }
    });
});
// example http://localhost:3000/getSpecific/2022-12-15
app.get('/getSpecific/:id', (req, res) => {
    const param = req.params.id
    console.log("got a request for /getspeficic",param);

    fs.readdir(PATH_TO_DATA, (err, files) => {
        if (err) {
            console.log(err)
            res.status(500).send({ error: 'Error reading data directory or the specific file must have been compressed check on compressed url' });
        } else {
            res.type('text/csv');
            const latestFile = files.filter(item => item === param).pop();
            console.log(latestFile);
            res.sendFile(PATH_TO_DATA + '/' + latestFile);
        }
    });
})

app.get('/getLatestCompressed', (req, res) => {
    console.log("got a request for /getLatestCompressed");
    fs.readdir(PATH_TO_COMPRESSED, (err, files) => {
        if (err) {
            console.log(err)
            res.status(500).send({ error: 'Error reading data directory' });
        } else {
            res.type('application/x-bzip2');
            const latestFile = files.sort().pop(); // Get the latest file
            res.sendFile(PATH_TO_COMPRESSED + '/' + latestFile);
        }
    });
});
// example http://localhost:3000/getSpecific/2022-12-15
app.get('/getSpecificCompressed/:id', (req, res) => {
    const param = req.params.id
    console.log("got a request for /getSpeficicCompressed", param);

    fs.readdir(PATH_TO_COMPRESSED, (err, files) => {
        if (err) {
            console.log(err)
            res.status(500).send({ error: 'Error reading data directory ' });
        } else {
            res.type('application/x-bzip2');
            const latestFile = files.filter(item => item === param+'.bz2').pop();
            console.log(latestFile);
            res.sendFile(PATH_TO_COMPRESSED + '/' + latestFile);
        }
    });
})





app.listen(3000, () => console.log('Listening on port 3000!'));