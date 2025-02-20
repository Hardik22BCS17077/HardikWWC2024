const API_URL = 'http://localhost:5000/api/energy';

export const getEnergyData = async (userId) => {
  const response = await fetch(`${API_URL}/${userId}`);
  return response.json();
};

export const addEnergyData = async (data) => {
  const response = await fetch(`${API_URL}/add`, {
    method: 'POST',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify(data),
  });
  return response.json();
};
