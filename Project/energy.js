const express = require('express');
const { getEnergyData, addEnergyData, predictBill } = require('../controllers/energyController');
const router = express.Router();

router.get('/:userId', getEnergyData);
router.post('/add', addEnergyData);
router.get('/predict/:userId', predictBill);

module.exports = router;
